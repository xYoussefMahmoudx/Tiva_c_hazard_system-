# include "tm4c123gh6pm.h"


void mag_ADC_init(void){
  
    SYSCTL_RCGCGPIO_R |= (1<<4);   /* Enable Clock to GPIOE or PE3/AN0 */
    SYSCTL_RCGCADC_R |= (1<<0);    /* AD0 clock enable*/
    
    /* initialize PE3 for AIN0 in-----put  */
    GPIO_PORTE_AFSEL_R |= (1<<3);       /* enable alternate function */
    GPIO_PORTE_DEN_R &= ~(1<<3);        /* disable digital function */
    GPIO_PORTE_AMSEL_R |= (1<<3);       /* enable analog function */
   
    /* initialize sample sequencer3 */
    ADC0_ACTSS_R  &= ~(1<<3);        /* disable SS3 during configuration */
    ADC0_EMUX_R &= ~0xF000;    /* software trigger conversion */
    ADC0_SSMUX3_R = 0;         /* get input from channel 0 */
    ADC0_SSCTL3_R |= (1<<1)|(1<<2);        /* take one sample at a time, set flag at 1st sample */
    ADC0_ACTSS_R |= (1<<3);         /* enable ADC0 sequencer 3 */ 
}


void mag_start_sampling(void){
  
  
  ADC0_PSSI_R |= (1<<3);        /* Enable SS3 conversion or start sampling data from AN0 */
 while((ADC0_RIS_R & 8) == 0) ; 
}
void mag_clear_sample_flag(void){
   ADC0_ISC_R = 8;  
  
}


void mag_sensor(void){
  
  
       /* Enable Clock to GPIOE or PE3/AN0 */
     SYSCTL_RCGCGPIO_R  |= (1<<4);
     while((SYSCTL_PRGPIO_R & 0x00000010) == 0){}; 
     
     GPIO_PORTE_CR_R |=  0x04;
    //GPIO_PORTF_PUR_R |= 0x10;
    GPIO_PORTE_DIR_R &= ~0x04;
    GPIO_PORTE_DEN_R |=  0x04;
}