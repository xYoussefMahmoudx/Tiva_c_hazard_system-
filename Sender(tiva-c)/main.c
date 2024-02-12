
#include "tm4c123gh6pm.h"
#include "laserDiode.h"
#include "ultrasonic.h"
#include "bluetoothModule.h"
#include <stdio.h>
#include "types.h"
#include <stdint.h>
#include <stdlib.h>
#include "fumeSensor.h"
#include "magneticSensor.h"
#include "startstop.h"

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
         // UART5_init(); // call HC05_init() to initialze UART5 of TM4C123GH6PM
	
	/* Set PF1, PF2 and PF3 as digital output pins */
	
	//SYSCTL_RCGCGPIO_R |= 0x20;   /* enable clock to GPIOF */
        //GPIO_PORTF_DIR_R |= 0x0E;         //set PF1, PF2 and PF3 as digital output pin
        //GPIO_PORTF_DEN_R |= 0x0E;         // CON PF1, PF2 and PF3 as digital GPIO pins
  	
	
	//while(1)
	//{
         
	//	char c = Bluetooth_Read();          /* get a character from UART5 */
	//	 printf("%c\n",c);
/* Check the received character and take action to control onboard LEDs of TM4C123 */
/* Send status string to Andriod app after turning on/off LEDs */

        //if( c=='A'){
			
	//		Bluetooth_Write_String("RED LED ON\n");
	//	}
	//	else if( c=='B'){
			
	//		Bluetooth_Write_String("RED LED OFF\n");
	//	}
	//	else if( c=='C'){
			
	//		Bluetooth_Write_String("BLUE LED ON\n");
	//	}
	//	else if( c=='D'){
			
	//		Bluetooth_Write_String("BLUE LED OFF\n");
	//	}
	//	else if( c=='E'){
			
	//		Bluetooth_Write_String("GREEN LED ON\n");
	//	}
	//	else if( c=='F'){
			
	//		Bluetooth_Write_String("GREEN LED OFF\n");
	//	}	
	




//}
  
  
  
  // unsigned int adc_value;
   //ADC_init();
   
//  while(1)
    //{
  //     start_sampling();
   /* Wait untill sample conversion completed*/
     //   adc_value = ADC0_SSFIFO3_R; /* read adc coversion result from SS3 FIFO*/
     //   clear_sample_flag();         /* clear coversion clear flag bit*/
			/*control Green PF3->LED */
	//printf("%d\n",adc_value);
  //  }

  
  
  
  
  
  
  
      /*ADC_init();  // Initialize ADC
    unsigned int adc_value;
    while (1) {
        start_sampling();  // Start ADC sampling
        
        
        adc_value = ADC0_SSFIFO3_R;  // Read ADC conversion result from SS3 FIFO
        clear_sample_flag();         // Clear conversion completion flag
        
        
        printf("%d\n", adc_value);
    }  // Print ADC value*/
        
/*unsigned int dig_value;
  
while(1){
  mag_sensor();
  dig_value= GPIO_PORTE_DATA_R & (0x04);
  printf("%d\n",dig_value);
  Delay(100);
}*/
  
  
  /*laserdiode function:
state ==> 1 fume
state ==> 2 ultrasonic
state ==> 3 magnetic
state ==> 4 ON
state ==> 5 Off
*/
  uint32 dig_value;
  uint32 adc_value;
   UART5_init();
  laserDiodeInit();
  delayInit();
  ADC_init();
  mag_sensor();
  uint8 on_flag=0;
  Timer0ACapture_init();
  while (1){
    if(start_btn()){
      on_flag=1;
    }
    while(on_flag){
      if(stop_btn()){
      on_flag=0;
      }
  adc_value=fume_sensor();
    if(adc_value>1500){
      laserDiode(1);
      Bluetooth_Write_String("Fire detected danger danger ...\n");
    }
    printf("%d adc \n",adc_value);
    
  
     dig_value= GPIO_PORTE_DATA_R & (0x04);
    if(dig_value>=4){
       laserDiode(3);
        Bluetooth_Write_String("Intrusion detected danger danger ...\n");
    }
     printf("%d dig \n",GPIO_PORTE_DATA_R & (0x04));
    
    time = Measure_distance(); 
    distance = (time * 10625)/10000000; 
    if(distance>10){
      
      laserDiode(2);
      Bluetooth_Write_String("door has opened\n");
      
    }
 printf("%d dist \n",distance);
    }
   // Delay(1000);
  }
  
  
/*  portf_init();
  
  while(1){
  printf("%d stop \n",stop_btn());
  }*/
  return 0;
}
