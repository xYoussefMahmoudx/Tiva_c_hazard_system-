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
void laserDiodeInit(){
SYSCTL_RCGCGPIO_R  |= 0x08;
  while((SYSCTL_PRGPIO_R & 0x00000008) == 0){};
  
 // GPIO_PORTA_LOCK_R = 0x4C4F434B;
  
  GPIO_PORTD_CR_R |=  0x04;
  //GPIO_PORTF_PUR_R |= 0x10;
  GPIO_PORTD_DIR_R |= 0x04;
  GPIO_PORTD_DEN_R |=  0x04;
}
void laserDiode(uint8 state){
  
  
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
void delayInit() {
    SYSCTL_RCGCTIMER_R |= 0x04;      // Enable and provide a clock to Timer Block 0 in Run mode
}
void delay(uint32 period){
  TIMER2_CTL_R = 0x00;             // Disable Timer A during configuration
    TIMER2_CFG_R = 0x00;             // 32-bit configuration
    TIMER2_TAMR_R = 0x02;            // Configure Timer A in periodic mode
    TIMER2_TAILR_R = 16000*period - 1;       // Load value for a 1ms delay at 16 MHz clock
    TIMER2_CTL_R = 0x01;   // Enable Timer A with default settings
    while ((TIMER2_RIS_R & 0x01) == 0){};   // Wait until Timer A timeout flag is set
    TIMER2_ICR_R = 0x01;                   // Clear Timer A timeout flag
    
  /*
  SysTickDIsable();
  NVIC_ST_CTRL_R |=(1<<2);
  SysTickPeriodSet(period);
  NVIC_ST_CURRENT_R &= 0x00;
  SysTickEnable();
  while(!SysTickIsTimeOut()){};*/
  
  
}
void fumeSensorSendData(){
  diodeOn();
  delay(750);
  diodeOff();
  delay(1000);
  diodeOn();
  delay(500);
  diodeOff();
   delay(1000);
  diodeOn();
  delay(500);
  diodeOff();
  delay(1500);
  /*delay(2100);
  diodeOn();
  delay(1000);
  diodeOff();*/
}
void ultrasonicSensorSendData(){
  diodeOn();
  delay(750);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(1000);
  /*delay(1010);
  diodeOn();
  delay(1010);
  diodeOff();
  delay(1010);*/
}
void magneticSensorSendData(){
  diodeOn();
  delay(750);
  diodeOff();
  delay(400);
  diodeOn();
  delay(400);
  diodeOff();
  delay(400);
  diodeOn();
  delay(400);
  diodeOff();
  delay(400);
  diodeOn();
  delay(400);
  diodeOff();
  delay(400);
  diodeOn();
  delay(400);
  diodeOff();
  delay(600);
  /*delay(1100);
  diodeOn();
  delay(2100);
  diodeOff();*/
}
void OnSendData(){
  diodeOn();
  delay(750);
  diodeOff();
  delay(300);
  diodeOn();
  delay(300);
  diodeOff();
  delay(300);
  diodeOn();
  delay(300);
  diodeOff();
  delay(300);
  diodeOn();
  delay(300);
  diodeOff();
  delay(300);
  diodeOn();
  delay(300);
  diodeOff();
  delay(600);
  /*
  delay(100);
  diodeOn();
  delay(1000);
  diodeOff();
  delay(2100);*/
}
void OffSendData(){
  diodeOn();
  delay(750);
  diodeOff();
  delay(250);
  diodeOn();
  delay(250);
  diodeOff();
  delay(250);
  diodeOn();
  delay(250);
  diodeOff();
  delay(250);
  diodeOn();
  delay(250);
  diodeOff();
  delay(250);
  diodeOn();
  delay(250);
  diodeOff();
  delay(250);
  diodeOn();
  delay(250);
  diodeOff();
  delay(500);
  /*delay(100);
  diodeOn();
  delay(1100);
  diodeOff();
  delay(1100);
  diodeOn();
  delay(1100);
  diodeOff();*/
}
void testdiode(){
  delay(250);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
  diodeOn();
  delay(500);
  diodeOff();
  delay(500);
}