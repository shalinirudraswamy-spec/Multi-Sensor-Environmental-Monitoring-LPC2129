#include <LPC21xx.H>
#include"header.h"

void lcd_data(unsigned char data){
 IOCLR1=0XFE0000;
 IOSET1=(data&0xf0)<<16;
 IOSET1=1<<17;
 IOCLR1=1<<18;
 IOSET1=1<<19;
 delay_ms(2);
 IOCLR1=1<<19;

 IOCLR1=0XFE0000;
 IOSET1=(data&0x0f)<<20;
 IOSET1=1<<17;
 IOCLR1=1<<18;
 IOSET1=1<<19;
 delay_ms(2);
 IOCLR1=1<<19;
}

void lcd_cmd(unsigned char cmd){
 IOCLR1=0XFE0000;
 IOSET1=(cmd&0xf0)<<16;
 IOCLR1=1<<17;
 IOCLR1=1<<18;
 IOSET1=1<<19;
 delay_ms(2);
 IOCLR1=1<<19;

 IOCLR1=0XFE0000;
 IOSET1=(cmd&0x0f)<<20;
 IOCLR1=1<<17;
 IOCLR1=1<<18;
 IOSET1=1<<19;
 delay_ms(2);
 IOCLR1=1<<19;
}

void lcd_init(void){
 IODIR1=0xFE0000;
 lcd_cmd(0x2);
 lcd_cmd(0x28);
 lcd_cmd(0x0e);
 lcd_cmd(0x01);
}

void lcd_str(char *p){
 while(*p){
 lcd_data(*p);
 p++;
}
}

int lcd_len(char *p){
int i;
for(i=0;p[i];i++);
return i;
}

void lcd_int(int num){
	int i,a[10];
	 if(num==0)
	 lcd_data(0+48);

	 else if(num<0){
		num=-num;
		lcd_data('-');
	 }

	 i=0;
	 while(num>0){
	 a[i]=num%10;
	 num/=10;
	 i++;
	 }

	 for(i=i-1;i>=0;i--)
	 lcd_data(a[i]+48);
}

void lcd_float(float num){
 	int i;
	float f;
	
	if(num<0){
		num=-num;
		lcd_data('-');
		}
	 i=num;
	 f=(num-i)*100;

	 lcd_int(i);
	 lcd_data('.');
	 lcd_int(f);

}
