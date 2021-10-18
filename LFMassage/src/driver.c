/*
 * driver.c
 *
 *  Created on: 2021. 10. 12.
 *      Author: donny
 */
#include <SI_EFM8BB1_Register_Enums.h>
#include "driver.h"

SI_SBIT(LEDR, SFR_P0, 3);
SI_SBIT(LEDG, SFR_P0, 4);
SI_SBIT(LEDB, SFR_P0, 5);
SI_SBIT(IRLED, SFR_P0, 6);
SI_SBIT(BUZZ, SFR_P0, 7);
SI_SBIT(SWNEG, SFR_P1, 0);
SI_SBIT(SWPOS, SFR_P1, 1);
SI_SBIT(SW, SFR_P1, 2);

bool btn_plus = false;
bool btn_mode = false;
bool btn_minus = false;

uint32_t sens_mv;
bool sensing = false;

void delay(int val)
{
  int i, j;
  for (i = val; i != 0; i--) {
      for (j = 0; j < 10000; j++) {
          NOP();
      }
  }
}

void setBtnPlus(bool pressed)
{
  btn_plus = pressed;
}

void setBtnMode(bool pressed)
{
  btn_mode = pressed;
}

void setBtnMinus(bool pressed)
{
  btn_minus = pressed;
}

bool getBtnPlus(void)
{
  return btn_plus;
}

bool getBtnMode(void)
{
  return btn_mode;
}

bool getBtnMinus(void)
{
  return btn_minus;
}

void setLedRed(bool on)
{
  LEDR = !on;
}

void setLedGrn(bool on)
{
  LEDG = !on;
}

void setLedBlu(bool on)
{
  LEDB = !on;
}

void setIrLed(bool on)
{
  IRLED = !on;
}

void toggleBuzz(void)
{
  BUZZ = !BUZZ;
}

void offBuzz(void)
{
  BUZZ = 0;
}

void toggleSwitch(void)
{
  SW = !SW;
}

void offSwitch(void)
{
  SW = 0;
  SWPOS = 0;
  SWNEG = 0;
}

void pulseNeg(int width)
{
  int i;
  SWNEG = 1;
  for (i = 0; i < width; i++) {
      NOP();
  }
  SWNEG = 0;
}

void pulsePos(int width)
{
  int i;
  SWPOS = 1;
  for (i = 0; i < width; i++) {
      NOP();
  }
  SWPOS = 0;
}

void pulseBoth(int width)
{
  int i;
  SWPOS = 1;
  SWNEG = 1;
  for (i = 0; i < width; i++) NOP();
  SWPOS = 0;
  SWNEG = 0;
}

void charge(uint32_t mv)
{
  while(getSens() < mv) {
      WDTCN = 0xA5;
  }
  SW = 0;
}

uint32_t getSens(void)
{
  sensing = true;
  TMR2CN0_TR2 = 1;
  while (sensing);
  TMR2CN0_TR2 = 0;
  return sens_mv;
}

void driver_make_shock(int pw, uint32_t amp)
{
  TMR2CN0_TR2 = 1;
  pulsePos(pw);
  NOP();
  pulseNeg(pw);
  charge(amp);
  TMR2CN0_TR2 = 0;
}

void driver_updateSens(uint32_t mV)
{
  sens_mv = mV;
  sensing = false;
}
