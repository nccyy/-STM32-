#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "SmartCar.h"
#include "Serial.h"
#include "HCSR04.h"
#include "Servo.h"
#include "LineWalking.h"

uint8_t RxData,Num;
int main(void)
{
	OLED_Init();	
	SmartCar_Init();
	Serial_Init();
	HCSR04_Init();
	Servo_Init();
	LineWalking_Init();
	Servo_SetAngle(90);
	OLED_ShowString(1,1,"Distance:");
	OLED_ShowString(2,4,"CM");
	Delay_ms(310);
	while(1)
	{
		if(Serial_GetRxFlag()==1)
		{
			RxData=Serial_GetRxData();
		}
		
		if(RxData==0x40)
		{
			Num=1;
		}
		if(RxData==0x41)
		{
			Num=2;
		}
		if(RxData==0x42)
		{
			Num=3;
		}
		if(RxData==0x43)
		{
			Num=4;
		}
		if(RxData==0x44)
		{
			Num=5;
		}
		if(RxData==0x45)
		{
			Num=6;
		}
		if(RxData==0x46)
		{
			Num=7;
		}
		if(RxData==0x47)
		{
			Num=8;
		}
		if(RxData==0x48)
		{
			Num=9;
		}
		switch(Num)
		{
			case 1:Move_Forward();
		  break;
			case 2:Move_Backward();
		  break;
			case 3:Car_Stop();
		  break;
			case 4:Turn_Left(50);
		  break;
			case 5:Turn_Right(50);
		  break;
			case 6:Clockwise_Rotation();
		  break;
			case 7:CounterClockwise_Rotation();
		  break;
			case 8:LineWalking();
		  break;
			case 9:AvoidObstacle();
		  break;
			default:
				break;
		}


	}
		
}
	
	


