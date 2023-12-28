
#include "tm4c123gh6pm.h"
#include "laserDiode.h"
#include "ultrasonic.h"
#include "bluetoothModule.h"
#include <stdio.h>
#include "types.h"
#include <stdint.h>
#include <stdlib.h>

uint32 time; /*stores pulse on time */
uint32 distance; /* stores measured distance value */
char mesg[20];  /* string format of distance value */

int main()
{

 //laserDiode('o');
  
  //laserDiode('f');
  //laserDiode();
  //Timer0ACapture_init();  /*initialize Timer0A in edge edge time */
//UART5_init(); /* initialize UART5 module to transmit data to computer */
	//while(1)
	//{
//time = Measure_distance(); /* take pulse duration measurement */ 
//distance = (time * 10625)/10000000; /* convert pulse duration into distance */
//printf("%d",45);
//printf("%u \n", distance);
//sprintf(mesg, "\r\nDistance = %d cm", distance); /*convert float type distance data into string */
//printstring(mesg); /*transmit data to computer */
//Delay(2000); 
          UART5_init(); // call HC05_init() to initialze UART5 of TM4C123GH6PM
	
	/* Set PF1, PF2 and PF3 as digital output pins */
	
	SYSCTL_RCGCGPIO_R |= 0x20;   /* enable clock to GPIOF */
        GPIO_PORTF_DIR_R |= 0x0E;         //set PF1, PF2 and PF3 as digital output pin
        GPIO_PORTF_DEN_R |= 0x0E;         // CON PF1, PF2 and PF3 as digital GPIO pins
  	
	
	while(1)
	{
         
		char c = Bluetooth_Read();          /* get a character from UART5 */
		 printf("%c\n",c);
/* Check the received character and take action to control onboard LEDs of TM4C123 */
/* Send status string to Andriod app after turning on/off LEDs */

        if( c=='A'){
			
			Bluetooth_Write_String("RED LED ON\n");
		}
		else if( c=='B'){
			
			Bluetooth_Write_String("RED LED OFF\n");
		}
		else if( c=='C'){
			
			Bluetooth_Write_String("BLUE LED ON\n");
		}
		else if( c=='D'){
			
			Bluetooth_Write_String("BLUE LED OFF\n");
		}
		else if( c=='E'){
			
			Bluetooth_Write_String("GREEN LED ON\n");
		}
		else if( c=='F'){
			
			Bluetooth_Write_String("GREEN LED OFF\n");
		}	
	




}
  return 0;
}
