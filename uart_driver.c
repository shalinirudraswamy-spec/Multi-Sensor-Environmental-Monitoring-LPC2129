#include <LPC21xx.H>    
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

void uart_init(unsigned int baud){
 unsigned int result,pclk;

 if(VPBDIV==0)
 pclk=15000000;
 else if(VPBDIV==1)
 pclk=60000000;
 else if(VPBDIV==2)
 pclk=30000000;

 result =pclk/(baud*16);

 PINSEL0|=0X5;
 U0LCR=0X83;
 U0DLL=result&0xff;
 U0DLM=(result>>8)&0xff;
 U0LCR=0X3;
} 

void uart_tx(unsigned char data){
 U0THR=data;
 while(THRE==0);
} 

unsigned char uart_rx(void){
 while(RDR==0);
 return U0RBR;
} 

void uart_str(char *p){

while(*p){
	uart_tx(*p);
	p++;
}
}

void uart_tx_int(int num){
  int i=0,a[10];

	  if(num ==0){
	  uart_tx('0');
	  }

	  if(num < 0){
	  num=-num;
	  uart_tx('-');
	  }

	  i=0;
	  while(num){
	  a[i]=num%10;
	  num/=10;
	  i++;
	  }

	 for(i--;i>=0;i--)
	 uart_tx('0'+a[i]);
}

void uart_tx_float(float num){
int i,j;

if(num ==0){
uart_tx('0');
}

if(num < 0){
num=-num;
uart_tx('-');
}

i=num;
j=(num-i)*10000;

uart_tx_int(i);
uart_tx('.');
uart_tx_int(j);
}
