#include "pwm4all.h"

void pwm4all::beginRGB(){
  //Disable interrupts
  SREG = (SREG & 0b01111111);
  //Enable timer interrupts
  TIMSK2 = TIMSK2|0b00000110;
  //Timer configuration
  TCCR2B = 0b00000011;
  TCCR2A = 0b00000001;
  //Enable interrupts
  SREG = (SREG & 0b01111111) | 0b10000000;
  //Set pins as output
  GREEN_DIRECTION_REG = (1<<GREEN_DIRECTION_BIT) | (1<<RED_DIRECTION_BIT);
  //RED_DIRECTION_REG = (1<<RED_DIRECTION_BIT);
}

void pwm4all::rojo(byte value){
  OCR2A = value;
}

void pwm4all::verde(byte value){
  OCR2B = value;
}

void pwm4all::azul(byte value){
  //OCR2B = value;
}

void pwm4all::RGB(byte red, byte green, byte blue){
  OCR2A = red;
  OCR2B = green;
}

//RED interrpt function
ISR (TIMER2_COMPA_vect)
{
   RED_PIN_REG = _BV(RED_PIN_BIT);
}

//GREEN interrpt function
ISR (TIMER2_COMPB_vect)
{
  GREEN_PIN_REG = _BV(GREEN_PIN_BIT);
}
