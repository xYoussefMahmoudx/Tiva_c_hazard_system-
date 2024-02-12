# include "tm4c123gh6pm.h"


void mag_sensor(void){
  
  
       /* Enable Clock to GPIOE or PE3/AN0 */
     SYSCTL_RCGCGPIO_R  |= (1<<4);
     while((SYSCTL_PRGPIO_R & 0x00000010) == 0){}; 
     
     GPIO_PORTE_CR_R |=  0x04;
    //GPIO_PORTF_PUR_R |= 0x10;
    GPIO_PORTE_DIR_R &= ~0x04;
    GPIO_PORTE_DEN_R |=  0x04;
}