#define F_CPU 12000000UL
#include <avr/io.h>
#include <util/delay.h>
/*
porta for keypad

*/

#include "lcd.h"

void display(int);
int num[10]={1223,2123,3122,2131,2108,2109,2110,2111,2222,2113};
int bal[10]={200,50,30,8,55,24,36,24,99,100};
char name[10][10]={"Mr. XYZ","Mr. ABC","Mr. DEF","Mr. GHI","Mr. JKL","Mr. MNO","Mr. PQR","Mr. STU","Mr. VWX","Mr. WXY"};


int main(void)
{
   unsigned char i;
	DDRA=0b00000000;//PORTA Input port connected to Sensors
	//DDRB=0b00111111;
	DDRD=0b11111100;//PORTD as output Port connected to motor enable pins
	//PORTD=0b11110000;

	int key=0,key2=0;
   //Initialize LCD module
   LCDInit(LS_BLINK|LS_ULINE);

   //Clear the screen
   LCDClear();

   //Simple string printing
   LCDWriteString("Welcome ");

   //A string on line 2
   LCDWriteStringXY(0,1,"Loading ");

   //Print some numbers
   for (i=0;i<101;i+=1)
   {
      LCDWriteIntXY(9,1,i,3);
      LCDWriteStringXY(12,1,"%");
      _delay_loop_2(0);
  /*    _delay_loop_2(0);
      _delay_loop_2(0);
      _delay_loop_2(0);*/

   }


   //Clear the screen
_delay_ms(3000);
   LCDClear();





	while(1)
	{	
		int id=0;
		int a=0;
		
		//for(int j=1;j<3;j++)
		while(id<1000)
		{
		int loop=1;
		key=PINA;//&0b00000011;
		key2=PIND&0b00000011;
		
		if(key2==0b00000011)
		{if(key==0xFF)
		{loop=0;}
		}


if(loop==1)
{
			if(key==0b11111110)
		{a=1;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b11111101)
		{a=4;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b11111011)
		{a=7;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b11110111)
		{a=8;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b11101111)
		{a=5;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b11011111)
		{a=2;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b10111111)
		{a=0;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key==0b01111111)
		{a=9;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key2==0b00000010)
		{a=3;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	else	if(key2==0b00000001)
		{a=6;LCDWriteIntXY(5,0,a,1);_delay_ms(800);LCDClear();}
		
	

		id=id*10+a;
	/*	_delay_ms(1500);
		PORTC=0x01;
		_delay_ms(300);
		PORTC=0x00;
		_delay_ms(100);*/
}//loop==1

		}//4 digit id ****
 		LCDWriteIntXY(6,1,id,4);
	   _delay_ms(3000);
   	   LCDClear();
		display(id);
		
	}

}

void display(int i)
{	int k=0;
		for(int j=0;j<10;j++)
		{
		if(i==num[j])
		{
			k=j+1;
			LCDWriteString("WELCOME");
 			LCDWriteStringXY(0,1,name[j]); 
			_delay_ms(2000);
			LCDClear();

			if(bal[j]>10)
			{
				bal[j]-=10;

			   LCDWriteString("Left Balance");
			   LCDWriteIntXY(9,1,bal[j],3);
			   _delay_ms(3000);
			   LCDClear();

			LCDWriteString("THANK YOU");
 			LCDWriteStringXY(0,1,"VISIT AGAIN"); 
			   _delay_ms(3000);
			   LCDClear();
			}//inner if
			else if(bal[j]<11)
			{
				LCDWriteString("Insufficient Balance");
 				LCDWriteStringXY(0,1,"Please Recharge"); 
			   	_delay_ms(3000);
			   	LCDClear();
			}//inner else
		break;	
		}//main if
		
		}//for close

		if(k==0)
		{
			LCDWriteString("INVALID ID!!!");
			   _delay_ms(3000);
			   LCDClear();
		}//else 
		
		
		
}//func close
