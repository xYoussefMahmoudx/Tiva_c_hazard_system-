# include "tm4c123gh6pm.h"

void mag_ADC_init(void){
  
    SYSCTL_RCGCGPIO_R |= (1<<4);   /* Enable Clock to GPIOE or PE3/AN0 */
    SYSCTL_RCGCADC_R |= (1<<1);    /* AD0 clock enable*/
    
    /* initialize PE2 for AIN1 input  */
    
    GPIO_PORTE_AFSEL_R |= (1<<2);       /* enable alternate function */
    GPIO_PORTE_DEN_R &= ~(1<<2);        /* disable digital function */
    GPIO_PORTE_AMSEL_R |= (1<<2);       /* enable analog function */
   
    /* initialize sample sequencer3 */
    ADC1_ACTSS_R  &= ~(1<<3);        /* disable SS3 during configuration */
    ADC1_EMUX_R &= ~0xF000;    /* software trigger conversion */
    ADC1_SSMUX3_R = 0;         /* get input from channel 1 */
    ADC1_SSCTL3_R |= (1<<1)|(1<<2);        /* take one sample at a time, set flag at 1st sample */
    ADC1_ACTSS_R |= (1<<3);         /* enable ADC1 sequencer 3 */ 
}


void mag_start_sampling(void){
  
  
  ADC1_PSSI_R |= (1<<2);        /* Enable SS3 conversion or start sampling data from AN1 */
 while((ADC1_RIS_R & 8) == 0) ; 
}
void mag_clear_sample_flag(void){
   ADC1_ISC_R = 8;  
  
}


void mag_fumeSensor(void){
  
  
}