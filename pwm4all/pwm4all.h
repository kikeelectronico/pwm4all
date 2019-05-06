#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define GREEN_PIN_REG PIND
#define GREEN_PIN_BIT PIND7
#define GREEN_DIRECTION_REG DDRD
#define GREEN_DIRECTION_BIT DDD7

#define RED_PIN_REG PIND
#define RED_PIN_BIT PIND4
#define RED_DIRECTION_REG DDRD
#define RED_DIRECTION_BIT DDD4

class pwm4all
{

public:
  void beginRGB();
  void rojo(byte value);
  void verde(byte value);
  void azul(byte value);
  void RGB(byte red, byte green, byte blue);

};
