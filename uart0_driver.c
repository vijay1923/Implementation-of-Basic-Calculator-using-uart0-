#include<lpc21xx.h>
#include<stdio.h>
#include"header.h"

void uart0_init(unsigned int baud)
{
unsigned int result=0,pclk;
int a[]={15,60,30,15,15};
pclk=a[VPBDIV]* 1000000;
result=pclk/(16*baud);
PINSEL0|=5;
U0LCR=0x83;
U0DLM=(result >>8)&0xff;
U0DLL=result&0x00ff;
U0LCR=3;
}

#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data )
{
U0THR=data;
while(THRE == 0);
}
#define RBR (U0LSR&1)
unsigned char uart0_rx(void )
{
while(RBR == 0);
return U0RBR;
}

void uart0_tx_string(char *ptr)
{
while(*ptr)
{
U0THR =* ptr;
while(THRE == 0);
ptr++;
}
}
void uart0_tx_float(float num)
{
 char s[10]={0};
sprintf(s,"%f",num);
uart0_tx_string(s);
}
void uart0_tx_integer(int num)
{
 char s[10]={0};
sprintf(s,"%d",num);
uart0_tx_string(s);
}


char *uart0_rx_string(char *s, int ele)
{
int i;
for( i=0;i<ele; i++)
{
s[i]=uart0_rx();
if(s[i] == '\r')
{
s[i]=0;
break;
}
}
return
	s;
}
void uart0_hex(char ch)
{
char a,b;
uart0_tx_string("0x");
a=((ch/16))+48;
b=((ch%16))+48;
	uart0_tx(a);
	uart0_tx(b);
}
