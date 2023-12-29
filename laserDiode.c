# include "tm4c123gh6pm.h"
# include  "laserDiode.h"
# include  "types.h"
#include "stdbool.h"
/*
  fume 001
	ultrasonic 010
	magnetic 011
	ON 100
	OFF 101
*/
void fumeSensorSendData();
void ultrasonicSensorSendData();
void magneticSensorSendData();
void OnSendData();
void OffSendData();
void laserDiode(uint8 state){
  
  SYSCTL_RCGCGPIO_R  |= 0x08;
  while((SYSCTL_PRGPIO_R & 0x00000008) == 0){};
  
 // GPIO_PORTA_LOCK_R = 0x4C4F434B;
  
  GPIO_PORTD_CR_R |=  0x04;
  //GPIO_PORTF_PUR_R |= 0x10;
  GPIO_PORTD_DIR_R |= 0x04;
  GPIO_PORTD_DEN_R |=  0x04;
  //GPIO_PORTA_PCTL_R &= ~0x04;
  //GPIO_PORTA_AMSEL_R &= ~0x04;
 // GPIO_PORTA_AFSEL_R &=~0x04;
  switch (state){
  case 1:
    fumeSensorSendData();
    break;
  case 2:
    ultrasonicSensorSendData();
    break;
  case 3:
    magneticSensorSendData();
    break;
  case 4:
    OnSendData();
    break;
  case 5:
    OffSendData();
    break;
  }
}
void diodeOn(){
  GPIO_PORTD_DATA_R |=0x04;
}
void diodeOff(){
  GPIO_PORTD_DATA_R =0x00;
}

void SysTickDIsable(void){
  //Clear_Bit(NVIC_ST_CTRL_R,0);
  NVIC_ST_CTRL_R &= 0<<0;
}
void SysTickEnable(void){
  //Set_Bit(NVIC_ST_CTRL_R,0);
  NVIC_ST_CTRL_R |= 1<<0;
}
uint32 SysTickPeriodGet(void){
  return ((NVIC_ST_CURRENT_R+1)/16000000)*1000;
}
void SysTickPeriodSet(uint32 period){//period in ms
  
  NVIC_ST_RELOAD_R |= (period*16000)-1;
}
uint32 SysTickValueGet(void){
  return NVIC_ST_CURRENT_R;
}
bool SysTickIsTimeOut(void){
  return (NVIC_ST_CTRL_R<<16)&1;
}
void delay(uint32 period){
  SysTickDIsable();
  NVIC_ST_CTRL_R |=(1<<2);
  SysTickPeriodSet(period);
  NVIC_ST_CURRENT_R &= 0x00;
  SysTickEnable();
  while(!SysTickIsTimeOut()){};
  
  
}
void fumeSensorSendData(){
  diodeOn();
  delay(50);
  diodeOff();
  delay(450);
  diodeOn();
  delay(200);
  diodeOff();
}
void ultrasonicSensorSendData(){
  diodeOn();
  delay(50);
  diodeOff();
  delay(250);
  diodeOn();
  delay(200);
  diodeOff();
  delay(200);
}
void magneticSensorSendData(){
  diodeOn();
  delay(50);
  diodeOff();
  delay(250);
  diodeOn();
  delay(200);
  diodeOff();
  diodeOn();
  delay(200);
  diodeOff();
}
void OnSendData(){
  diodeOn();
  delay(50);
  diodeOff();
  delay(50);
  diodeOn();
  delay(200);
  diodeOff();
  delay(400);
}
void OffSendData(){
  diodeOn();
  delay(50);
  diodeOff();
  delay(50);
  diodeOn();
  delay(200);
  diodeOff();
  diodeOn();
  delay(200);
  diodeOff();
  delay(200);
}