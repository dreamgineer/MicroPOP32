#include <MicroPOP32.cpp>
#ifdef EXTRA_MOTORS
#ifdef NO_MOTOR
#error "Extra motors module cannot be used when motor control is disabled"
#endif
#define M3EN PA10
#define M4EN PB4
const int _OUT0[4] = {
    0x7FFF,
    0xBFFF,
    0xDFFF,
    0xEFFF};
const int _OUT1[4] = {
    0x8000,
    0x4000,
    0x2000,
    0x1000};
const int _EN[4] = {
    M1EN,
    M2EN,
    M3EN,
    M4EN};

void m(int num, int pow)
{
  int id = num - 1;
  if (pow >= 0)
    GPIOB->ODR &= _OUT0[id];
  else
    GPIOB->ODR &= _OUT1[id];
  analogWrite(_EN[id], constrain((pow * 255) / 100, -255, 255));
}
#endif
#ifdef EXTRA_ALIASES
#define a analogRead
#define d digitalRead
#define p pinMode
#define o digitalWrite
#define b beep
#endif