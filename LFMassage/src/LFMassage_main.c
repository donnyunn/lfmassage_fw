//=========================================================
// src/LFMassage_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "driver.h"
// $[Generated Includes]
// [Generated Includes]$

#define TIM0CLK       2083333          // Clock speed in Hz

void initialize(void);
void enter_lowpower(void);
void beep(void);
void Timer0_Delay (uint16_t us);

typedef enum {
  MODE_READY = 0,
  MODE_RED,
  MODE_GRN,
  MODE_BLU,
  MODE_MAX
} mode_t;
typedef enum {
  MAG_0 = 0,
  MAG_1,
  MAG_2,
  MAG_3,
  MAG_4,
  MAG_5,
  MAG_MAX
} magnitude_t;

mode_t mode = MODE_BLU;
magnitude_t mag = MAG_0;
static uint32_t chrg_ref_mV = 100;

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main (void)
{
  WDT_0_enter_DefaultMode_from_RESET();

//  Timer0_Delay(500);
  //P0MDIN |= P0MDIN_B1__DIGITAL;
  if (P0_B1 != 0) {
      enter_lowpower();
  }
  //P0MDIN &= ~P0MDIN_B1__DIGITAL;
  WDTCN = 0xA5;

  // Call hardware initialization routine
  enter_DefaultMode_from_RESET();

  initialize();
  IE_EA = 1;

  while (1) 
  {
      WDTCN = 0xA5;
    // $[Generated Run-time code]
    // [Generated Run-time code]$
      switch (mode) {
        case MODE_READY:
          break;
        case MODE_RED:
          TMR2CN0_TR2 = 1;
          pulseNeg(100);
          Timer0_Delay(100);
          pulseNeg(100);
          Timer0_Delay(100);
          TMR2CN0_TR2 = 0;
          Timer0_Delay(2000);
          break;
        case MODE_GRN:
          break;
        case MODE_BLU:
          break;
      }

      if (getBtnMode()) {
          setBtnMode(false);
          beep();

          mode++;
          if (mode == MODE_MAX) mode = MODE_READY;

          switch (mode) {
            case MODE_READY:
              setLedRed(false);
              setLedGrn(false);
              setLedBlu(false);
              setIrLed(false);
              beep();
              break;
            case MODE_RED:
              setLedRed(true);
              setLedGrn(false);
              setLedBlu(false);
              setIrLed(true);
              Timer0_Delay(100);
              break;
            case MODE_GRN:
              setLedRed(false);
              setLedGrn(true);
              setLedBlu(false);
              setIrLed(true);
              Timer0_Delay(100);
              break;
            case MODE_BLU:
              setLedRed(false);
              setLedGrn(false);
              setLedBlu(true);
              setIrLed(true);
              Timer0_Delay(100);
              break;
          }
          beep();
      } else if (getBtnPlus()) {
          setBtnPlus(false);
          mag++;
          if (mag == MAG_MAX) mag--;
          switch (mag) {
            case MAG_0: chrg_ref_mV = 100; break;
            case MAG_1: chrg_ref_mV = 300; break;
            case MAG_2: chrg_ref_mV = 500; break;
            case MAG_3: chrg_ref_mV = 700; break;
            case MAG_4: chrg_ref_mV = 900; break;
            case MAG_5: chrg_ref_mV = 1100; break;
          }

          beep();
      } else if (getBtnMinus()) {
          setBtnMinus(false);
          if (mag != MAG_0) mag--;
          switch (mag) {
            case MAG_0: chrg_ref_mV = 100; break;
            case MAG_1: chrg_ref_mV = 300; break;
            case MAG_2: chrg_ref_mV = 500; break;
            case MAG_3: chrg_ref_mV = 700; break;
            case MAG_4: chrg_ref_mV = 900; break;
            case MAG_5: chrg_ref_mV = 1100; break;
          }

          beep();
      }
  }                             
}

void initialize(void)
{
  offSwitch();

  setLedRed(false);
  setLedGrn(false);
  setLedBlu(false);
  setIrLed(false);
}

void enter_lowpower(void)
{
  P0MDIN = 0;
  P0MDOUT = 0;
  P1MDIN = 0;
  P1MDOUT = 0;
//  RSTSRC |= RSTSRC_C0RSEF__SET;
  RSTSRC |= RSTSRC_WDTRSF__SET;

  // REG0CN |= REG0CN_STOPCF__SHUTDOWN;

  PCON0 |= PCON0_STOP__BMASK;
//  PCON0 = PCON0_IDLE__IDLE;
}

void beep(void)
{
  TMR3CN0 |= TMR3CN0_TR3__RUN;
  Timer0_Delay(200);
  TMR3CN0 &= ~TMR3CN0_TR3__RUN;
  offBuzz();
}

void Timer0_Delay (uint16_t ms)
{
   unsigned i;                         // Millisecond counter

   for (i = 0; i < ms; i++)            // Count microseconds
   {
      TCON &= ~0x30;                   // STOP Timer0 and clear overflow
      TH0 = (-TIM0CLK/1000) >> 8;    // Set Timer0 to overflow in 1us
      TL0 = -TIM0CLK/1000;
      TCON |= 0x10;                    // START Timer0
      while (TCON_TF0 == 0) {
          WDTCN = 0xA5;           // Wait for overflow
      }
   }
}

