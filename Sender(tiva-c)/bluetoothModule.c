# include "tm4c123gh6pm.h"
#include "bluetoothModule.h"
char Bluetooth_Read(void)  
{
    char data;
	  while((UART5_FR_R & (1<<4)) != 0); /* wait until Rx buffer is not full */
    data = UART5_DR_R ;  	/* before giving it another byte */
    return (unsigned char) data; 
}

void Bluetooth_Write(unsigned char data)  
{
    while((UART5_FR_R & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART5_DR_R = data;                  /* before giving it another byte */
}

void Bluetooth_Write_String(char *str)
{
  while(*str)
	{
		Bluetooth_Write(*(str++));
	}
}

