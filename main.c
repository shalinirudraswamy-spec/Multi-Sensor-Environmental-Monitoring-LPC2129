#include <LPC21xx.H>
#include "header.h"
#include <stdio.h>

#define WATER  ((IOPIN0 >> 5) & 1)

#define Green  (1 << 17)
#define Red    (1 << 18)

int main()
{
    unsigned int a_value = 0;
    unsigned int soil, ldr;
    float vout = 0, temp = 0;
    char a[100];

    /* LED initialization */
    IODIR0 |= Green | Red;

    /* Initial LED OFF */
    IOCLR0 = Green | Red;

    lcd_init();
    uart_init(9600);
    adc_init();

    while(1)
    {
        /* ============ TEMPERATURE ============ */

        a_value = adc_read(1);          // ADC CH1
        vout = (a_value * 3.3) / 1023;
        temp = (vout - 0.5) / 0.01;

        lcd_cmd(0x80);
        lcd_str("Temp:");
        lcd_float(temp);

        sprintf(a, "\r\nTemperature: %.2f C", temp);
        uart_str(a);


        /* ============ SOIL MOISTURE ============ */

        soil = adc_read(3);             // ADC CH3
        soil = (soil * 100) / 1023;

        sprintf(a, "\r\nSoil Moisture: %d %%", soil);
        uart_str(a);


        /* ============ LDR ============ */

        ldr = adc_read(2);              // ADC CH2

        if(ldr >= 600)
        {
            uart_str("\r\nLight Level: DARK");
        }
        else if(ldr >= 200)
        {
            uart_str("\r\nLight Level: NORMAL");
        }
        else
        {
            uart_str("\r\nLight Level: SUNNY");
        }


        /* ============ WATER SENSOR ============ */

        lcd_cmd(0xC0);
        lcd_str("Status:");

        if(WATER == 0)
        {
            uart_str("\r\nWater Sensor: NOT DETECTED");
            uart_str("\r\nSystem Status: SAFE");
            uart_str("\r\nLED Status: GREEN");

            lcd_str("SAFE");

            IOSET0 = Green;
            IOCLR0 = Red;
        }
        else
        {
            uart_str("\r\nWater Sensor: DETECTED");
            uart_str("\r\nSystem Status: ALERT");
            uart_str("\r\nLED Status: RED");

            lcd_str("ALERT");

            IOSET0 = Red;
            IOCLR0 = Green;
        }

        delay_ms(2000);
    }
}