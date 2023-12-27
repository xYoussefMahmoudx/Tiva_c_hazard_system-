
#include "tm4c123gh6pm.h"
#include "laserDiode.h"
#include "ultrasonic.h"
#include <stdio.h>
#include "types.h"

uint32 time; /*stores pulse on time */
uint32 distance; /* stores measured distance value */
char mesg[20];  /* string format of distance value */

int main()
{
  //laserDiode('o');
  
  //laserDiode('f');
  //laserDiode();
  Timer0ACapture_init();  /*initialize Timer0A in edge edge time */
//UART5_init(); /* initialize UART5 module to transmit data to computer */
	while(1)
	{
time = Measure_distance(); /* take pulse duration measurement */ 
distance = (time * 10625)/10000000; /* convert pulse duration into distance */
//printf("%d",45);
printf("%u \n", distance);
//sprintf(mesg, "\r\nDistance = %d cm", distance); /*convert float type distance data into string */
//printstring(mesg); /*transmit data to computer */
Delay(2000);
  return 0;
}
}
