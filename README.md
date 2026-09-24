# Multi-Sensor Environmental Monitoring System using LPC2129

## Project Description

This project is an ARM-based environmental monitoring system developed using the LPC2129 microcontroller.

The system monitors temperature, light intensity, soil moisture, and water detection using multiple sensors.

## Hardware Used

- LPC2129 ARM7 Microcontroller
- LM35 Temperature Sensor
- LDR Sensor
- Soil Moisture Sensor
- Water Sensor
- 16x2 LCD
- UART
- Green LED
- Red LED

## Sensor Connections

| Sensor | LPC2129 Connection |
|---|---|
| LM35 | ADC Channel 1 |
| LDR | ADC Channel 2 |
| Soil Moisture | ADC Channel 3 |
| Water Sensor | P0.5 |
| Green LED | P0.17 |
| Red LED | P0.18 |

## Features

- Temperature monitoring
- Light level monitoring
- Soil moisture monitoring
- Water detection
- LCD display
- UART monitoring through PC
- LED status indication

## Software

- Embedded C
- Keil µVision
- LPC2129
- ARM7

## Output

Example UART output:

Temperature: 30.50 C
Soil Moisture: 72 %
Light Level: NORMAL
Water Sensor: NOT DETECTED
System Status: SAFE
LED Status: GREEN