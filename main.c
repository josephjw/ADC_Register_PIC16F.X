/*
 * File:   main.c
 * Author: joestalin
 *
 * Created on July 25, 2021, 10:43 PM
 */


#include<pic.h>
#define RS RE2
#define RW RE1
#define EN RE0
#define LCD PORTD
#define _XTAL_FREQ 4000000
__CONFIG(0X2CE4);
int a,b,sum,j,k,l,m,n,o,p,s;
void delay(unsigned int t)
{
while(t--);
}
void pulse()
{
EN=1;
delay(1000);
EN=0;
delay(1000);
}
void type()
{
RW=0;
RS=0;
LCD=0X38;
pulse();
}
void on()
{
RW=0;
RS=0;
LCD=0X0E;
pulse();
}
void address(char x)
{
RW=0;
RS=0;
LCD=x;
pulse();
}
void address1(char y)
{
RW=0;
RS=0;
LCD=y;
pulse();
}
void display(char z)
{
RW=0;
RS=1;
LCD=z;
pulse();
}
void display1(char t)
{
RW=0;
RS=1;
LCD=t;
pulse();
}

void adc(char s)
{
ADCON0=s;
ADCON1=0x80;
GO=1;
while(GO);
a=ADRESL;
b=ADRESH;
if(b==0)
{
sum=a+0;
}
if(b==1)
{
sum=a+256;
}
if(b==2)
{
sum=a+512;
}
if(b==3)
{
sum=a+768;
}
j=sum/1000;
k=sum%1000;
l=k/100;
m=k%100;
n=m/10;
o=m%10;

display(j+48);
display(l+48);
display(n+48);
display(o+48);

}
void main()
{
PORTA=0X00;
TRISA=0X01;
ANSEL=0X01;
ANSELH=0X00;
PORTD=0X00;
TRISD=0X00;
PORTE=0X00;
TRISE=0X00;
type();
on();
while(1)
{
address(0X80);
adc(0x83);
}
}
