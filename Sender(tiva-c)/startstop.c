# include "tm4c123gh6pm.h"
#include "types.h"

void portf_init(void){
  
  SYSCTL_RCGCGPIO_R  |= 0x20;
  while((SYSCTL_PRGPIO_R & 0x00000020) == 0){};
  
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0x11;
  GPIO_PORTF_DIR_R |= 0x0E;
  GPIO_PORTF_DEN_R |= 0x1F;
  GPIO_PORTF_PUR_R |= 0x11;
  
}
uint8 start_btn(void){
  
 if((GPIO_PORTF_DATA_R & (0x10))==0)
   return 1 ;
 else 
   return 0;
}
uint8 stop_btn(void){
  
 if((GPIO_PORTF_DATA_R & (0x01))==0)
   return 1 ;
 else 
   return 0;
}