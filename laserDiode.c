# include "tm4c123gh6pm.h"
# include  "laserDiode.h"
# include  "types.h"

void laserDiode(uint8 on){
  
  SYSCTL_RCGCGPIO_R  |= 0x01;
  while((SYSCTL_PRGPIO_R & 0x00000001) == 0){};
  
 // GPIO_PORTA_LOCK_R = 0x4C4F434B;
  
  GPIO_PORTA_CR_R |=  0x04;
  //GPIO_PORTF_PUR_R |= 0x10;
  GPIO_PORTA_DIR_R |= 0x04;
  GPIO_PORTA_DEN_R |=  0x04;
  //GPIO_PORTA_PCTL_R &= ~0x04;
  //GPIO_PORTA_AMSEL_R &= ~0x04;
 // GPIO_PORTA_AFSEL_R &=~0x04;
  if(on=='o'){
    GPIO_PORTA_DATA_R |=0x04;}
  else{
    GPIO_PORTA_DATA_R =0x00;
  }
  
  
  
  
}

