#include "ch32fun.h"
//#include <stdio.h>

int main()
{
	SystemInit();
	// Enable GPIOs
	funGpioInitAll();
	
	funPinMode( PD0,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC0,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC1,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC2,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC3,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC4,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC5,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC6,     GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	funPinMode( PC7, GPIO_Speed_10MHz | GPIO_CNF_OUT_PP );
	
	funDigitalWrite(PC1, 0);
	funDigitalWrite(PC2, 0);
	funDigitalWrite(PC3, 0);
	funDigitalWrite(PC4, 0);
	funDigitalWrite(PC5, 0);
	funDigitalWrite(PC6, 0);
	funDigitalWrite(PC7, 0);

	while(1)
	{
		funDigitalWrite(PD0, 1);
		Delay_Us(50);
		funDigitalWrite(PD0, 0);
		Delay_Us(1);
	}
}
