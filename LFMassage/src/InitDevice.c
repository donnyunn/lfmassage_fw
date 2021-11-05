//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void
enter_DefaultMode_from_RESET (void)
{
  // $[Config Calls]
  WDT_0_enter_DefaultMode_from_RESET ();
  PORTS_0_enter_DefaultMode_from_RESET ();
  PORTS_1_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  ADC_0_enter_DefaultMode_from_RESET ();
  CMP_0_enter_DefaultMode_from_RESET ();
  TIMER01_0_enter_DefaultMode_from_RESET ();
  TIMER16_2_enter_DefaultMode_from_RESET ();
  TIMER16_3_enter_DefaultMode_from_RESET ();
  TIMER_SETUP_0_enter_DefaultMode_from_RESET ();
  EXTINT_0_enter_DefaultMode_from_RESET ();
  INTERRUPT_0_enter_DefaultMode_from_RESET ();
  // [Config Calls]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  /***********************************************************************
   - P0.0 is high. Set P0.0 to drive or float high
   - P0.1 is high. Set P0.1 to drive or float high
   - P0.2 is high. Set P0.2 to drive or float high
   - P0.3 is high. Set P0.3 to drive or float high
   - P0.4 is high. Set P0.4 to drive or float high
   - P0.5 is high. Set P0.5 to drive or float high
   - P0.6 is high. Set P0.6 to drive or float high
   - P0.7 is low. Set P0.7 to drive low
   ***********************************************************************/
  P0 = P0_B0__HIGH | P0_B1__HIGH | P0_B2__HIGH | P0_B3__HIGH | P0_B4__HIGH
      | P0_B5__HIGH | P0_B6__HIGH | P0_B7__LOW;
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  /***********************************************************************
   - P0.0 output is open-drain
   - P0.1 output is open-drain
   - P0.2 output is open-drain
   - P0.3 output is push-pull
   - P0.4 output is push-pull
   - P0.5 output is push-pull
   - P0.6 output is push-pull
   - P0.7 output is push-pull
   ***********************************************************************/
  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
      | P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__PUSH_PULL | P0MDOUT_B4__PUSH_PULL
      | P0MDOUT_B5__PUSH_PULL | P0MDOUT_B6__PUSH_PULL | P0MDOUT_B7__PUSH_PULL;
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  /***********************************************************************
   - P0.0 pin is configured for digital mode
   - P0.1 pin is configured for analog mode
   - P0.2 pin is configured for digital mode
   - P0.3 pin is configured for digital mode
   - P0.4 pin is configured for digital mode
   - P0.5 pin is configured for digital mode
   - P0.6 pin is configured for digital mode
   - P0.7 pin is configured for digital mode
   ***********************************************************************/
  P0MDIN = P0MDIN_B0__DIGITAL | P0MDIN_B1__ANALOG | P0MDIN_B2__DIGITAL
      | P0MDIN_B3__DIGITAL | P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL
      | P0MDIN_B6__DIGITAL | P0MDIN_B7__DIGITAL;
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  /***********************************************************************
   - P0.0 pin is skipped by the crossbar
   - P0.1 pin is skipped by the crossbar
   - P0.2 pin is skipped by the crossbar
   - P0.3 pin is skipped by the crossbar
   - P0.4 pin is skipped by the crossbar
   - P0.5 pin is skipped by the crossbar
   - P0.6 pin is skipped by the crossbar
   - P0.7 pin is skipped by the crossbar
   ***********************************************************************/
  P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
      | P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
      | P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

}

extern void
PBCFG_0_enter_DefaultMode_from_RESET (void)
{
  // $[XBR2 - Port I/O Crossbar 2]
  /***********************************************************************
   - Weak Pullups enabled 
   - Crossbar enabled
   ***********************************************************************/
  XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
  // [XBR2 - Port I/O Crossbar 2]$

  // $[PRTDRV - Port Drive Strength]
  // [PRTDRV - Port Drive Strength]$

  // $[XBR0 - Port I/O Crossbar 0]
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  // [XBR1 - Port I/O Crossbar 1]$

}

extern void
INTERRUPT_0_enter_DefaultMode_from_RESET (void)
{
  // $[EIE1 - Extended Interrupt Enable 1]
  /***********************************************************************
   - Enable interrupt requests generated by the ADINT flag
   - Disable ADC0 Window Comparison interrupt
   - Enable interrupt requests generated by the comparator 0 CPRIF or CPFIF
   flags
   - Disable CP1 interrupts
   - Disable all Port Match interrupts
   - Disable all PCA0 interrupts
   - Disable all SMB0 interrupts
   - Enable interrupt requests generated by the TF3L or TF3H flags
   ***********************************************************************/
  EIE1 = EIE1_EADC0__ENABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__ENABLED
      | EIE1_ECP1__DISABLED | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
      | EIE1_ESMB0__DISABLED | EIE1_ET3__ENABLED;
  // [EIE1 - Extended Interrupt Enable 1]$

  // $[EIP1 - Extended Interrupt Priority 1]
  // [EIP1 - Extended Interrupt Priority 1]$

  // $[IE - Interrupt Enable]
  /***********************************************************************
   - Enable each interrupt according to its individual mask setting
   - Enable interrupt requests generated by the INT0 input
   - Enable interrupt requests generated by the INT1 input
   - Disable all SPI0 interrupts
   - Disable all Timer 0 interrupt
   - Enable interrupt requests generated by the TF1 flag
   - Enable interrupt requests generated by the TF2L or TF2H flags
   - Disable UART0 interrupt
   ***********************************************************************/
  IE = IE_EA__ENABLED | IE_EX0__ENABLED | IE_EX1__ENABLED | IE_ESPI0__DISABLED
      | IE_ET0__DISABLED | IE_ET1__ENABLED | IE_ET2__ENABLED | IE_ES0__DISABLED;
  // [IE - Interrupt Enable]$

  // $[IP - Interrupt Priority]
  // [IP - Interrupt Priority]$

}

extern void
WDT_0_enter_DefaultMode_from_RESET (void)
{
  // $[Watchdog Timer Init Variable Declarations]
  uint32_t i;
  bool ea;
  // [Watchdog Timer Init Variable Declarations]$

  // $[WDTCN - Watchdog Timer Control]
  // Deprecated
  // [WDTCN - Watchdog Timer Control]$

  // $[WDTCN_2 - Watchdog Timer Control]

  // Feed WDT timer before disabling (Erratum WDT_E102)
  WDTCN = 0xA5;

  // Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
  for (i = 0; i < (2 * 3062500UL) / (10000 * 3); i++)
    {
      NOP ();
    }

  // Disable WDT before changing interval
  ea = IE_EA;
  IE_EA = 0;
  WDTCN = 0xDE;
  WDTCN = 0xAD;
  IE_EA = ea;

  // Delay 2 LFO cycles to ensure WDT is completely disabled
  for (i = 0; i < (2 * 3062500UL) / (10000 * 3); i++)
    {
      NOP ();
    }

  // Change WDT interval
  WDTCN = 4;

  // Start WDT
  WDTCN = 0xA5;

  // [WDTCN_2 - Watchdog Timer Control]$

}

extern void
TIMER16_2_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR2CN0_TR2_save;
  TMR2CN0_TR2_save = TMR2CN0 & TMR2CN0_TR2__BMASK;
  // Stop Timer
  TMR2CN0 &= ~(TMR2CN0_TR2__BMASK);
  // [Timer Initialization]$

  // $[TMR2CN0 - Timer 2 Control]
  // [TMR2CN0 - Timer 2 Control]$

  // $[TMR2H - Timer 2 High Byte]
  // [TMR2H - Timer 2 High Byte]$

  // $[TMR2L - Timer 2 Low Byte]
  // [TMR2L - Timer 2 Low Byte]$

  // $[TMR2RLH - Timer 2 Reload High Byte]
  /***********************************************************************
   - Timer 2 Reload High Byte = 0xFF
   ***********************************************************************/
  TMR2RLH = (0xFF << TMR2RLH_TMR2RLH__SHIFT);
  // [TMR2RLH - Timer 2 Reload High Byte]$

  // $[TMR2RLL - Timer 2 Reload Low Byte]
  /***********************************************************************
   - Timer 2 Reload Low Byte = 0xEB
   ***********************************************************************/
  TMR2RLL = (0xEB << TMR2RLL_TMR2RLL__SHIFT);
  // [TMR2RLL - Timer 2 Reload Low Byte]$

  // $[TMR2CN0]
  // [TMR2CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR2CN0 |= TMR2CN0_TR2_save;
  // [Timer Restoration]$

}

extern void
PORTS_1_enter_DefaultMode_from_RESET (void)
{
  // $[P1 - Port 1 Pin Latch]
  /***********************************************************************
   - P1.0 is low. Set P1.0 to drive low
   - P1.1 is low. Set P1.1 to drive low
   - P1.2 is low. Set P1.2 to drive low
   - P1.3 is high. Set P1.3 to drive or float high
   ***********************************************************************/
  P1 = P1_B0__LOW | P1_B1__LOW | P1_B2__LOW | P1_B3__HIGH;
  // [P1 - Port 1 Pin Latch]$

  // $[P1MDOUT - Port 1 Output Mode]
  /***********************************************************************
   - P1.0 output is push-pull
   - P1.1 output is push-pull
   - P1.2 output is push-pull
   - P1.3 output is open-drain
   ***********************************************************************/
  P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__PUSH_PULL
      | P1MDOUT_B2__PUSH_PULL | P1MDOUT_B3__OPEN_DRAIN;
  // [P1MDOUT - Port 1 Output Mode]$

  // $[P1MDIN - Port 1 Input Mode]
  /***********************************************************************
   - P1.0 pin is configured for digital mode
   - P1.1 pin is configured for digital mode
   - P1.2 pin is configured for digital mode
   - P1.3 pin is configured for analog mode
   ***********************************************************************/
  P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__DIGITAL | P1MDIN_B2__DIGITAL
      | P1MDIN_B3__ANALOG;
  // [P1MDIN - Port 1 Input Mode]$

  // $[P1SKIP - Port 1 Skip]
  /***********************************************************************
   - P1.0 pin is skipped by the crossbar
   - P1.1 pin is skipped by the crossbar
   - P1.2 pin is skipped by the crossbar
   - P1.3 pin is skipped by the crossbar
   ***********************************************************************/
  P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
      | P1SKIP_B3__SKIPPED;
  // [P1SKIP - Port 1 Skip]$

  // $[P1MASK - Port 1 Mask]
  // [P1MASK - Port 1 Mask]$

  // $[P1MAT - Port 1 Match]
  // [P1MAT - Port 1 Match]$

}

extern void
ADC_0_enter_DefaultMode_from_RESET (void)
{
  // $[ADC0CN1 - ADC0 Control 1]
  // [ADC0CN1 - ADC0 Control 1]$

  // $[ADC0MX - ADC0 Multiplexer Selection]
  /***********************************************************************
   - Select ADC0.11
   ***********************************************************************/
  ADC0MX = ADC0MX_ADC0MX__ADC0P11;
  // [ADC0MX - ADC0 Multiplexer Selection]$

  // $[ADC0CF - ADC0 Configuration]
  /***********************************************************************
   - SAR Clock Divider = 0x1F
   - ADC0 operates in 10-bit or 12-bit mode 
   - The on-chip PGA gain is 1
   - Normal Track Mode
   ***********************************************************************/
  ADC0CF = (0x1F << ADC0CF_ADSC__SHIFT) | ADC0CF_AD8BE__NORMAL
      | ADC0CF_ADGN__GAIN_1 | ADC0CF_ADTM__TRACK_NORMAL;
  // [ADC0CF - ADC0 Configuration]$

  // $[ADC0AC - ADC0 Accumulator Configuration]
  // [ADC0AC - ADC0 Accumulator Configuration]$

  // $[ADC0TK - ADC0 Burst Mode Track Time]
  // [ADC0TK - ADC0 Burst Mode Track Time]$

  // $[ADC0PWR - ADC0 Power Control]
  // [ADC0PWR - ADC0 Power Control]$

  // $[ADC0GTH - ADC0 Greater-Than High Byte]
  // [ADC0GTH - ADC0 Greater-Than High Byte]$

  // $[ADC0GTL - ADC0 Greater-Than Low Byte]
  // [ADC0GTL - ADC0 Greater-Than Low Byte]$

  // $[ADC0LTH - ADC0 Less-Than High Byte]
  // [ADC0LTH - ADC0 Less-Than High Byte]$

  // $[ADC0LTL - ADC0 Less-Than Low Byte]
  // [ADC0LTL - ADC0 Less-Than Low Byte]$

  // $[ADC0CN0 - ADC0 Control 0]
  /***********************************************************************
   - Enable ADC0 
   - ADC0 conversion initiated on overflow of Timer 2
   ***********************************************************************/
  ADC0CN0 &= ~ADC0CN0_ADCM__FMASK;
  ADC0CN0 |= ADC0CN0_ADEN__ENABLED | ADC0CN0_ADCM__TIMER2;
  // [ADC0CN0 - ADC0 Control 0]$

}

extern void
VREF_0_enter_DefaultMode_from_RESET (void)
{
  // $[REF0CN - Voltage Reference Control]
  /***********************************************************************
   - Disable the Temperature Sensor
   - The ADC0 ground reference is the GND pin
   - The internal reference operates at 1.65 V nominal
   - The ADC0 voltage reference is the VDD pin
   ***********************************************************************/
  REF0CN = REF0CN_TEMPE__TEMP_DISABLED | REF0CN_GNDSL__GND_PIN
      | REF0CN_IREFLVL__1P65 | REF0CN_REFSL__VDD_PIN;
  // [REF0CN - Voltage Reference Control]$

}

extern void
TIMER01_0_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  //Save Timer Configuration
  uint8_t TCON_save;
  TCON_save = TCON;
  //Stop Timers
  TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

  // [Timer Initialization]$

  // $[TH0 - Timer 0 High Byte]
  /***********************************************************************
   - Timer 0 High Byte = 0xFF
   ***********************************************************************/
  TH0 = (0xFF << TH0_TH0__SHIFT);
  // [TH0 - Timer 0 High Byte]$

  // $[TL0 - Timer 0 Low Byte]
  /***********************************************************************
   - Timer 0 Low Byte = 0xFF
   ***********************************************************************/
  TL0 = (0xFF << TL0_TL0__SHIFT);
  // [TL0 - Timer 0 Low Byte]$

  // $[TH1 - Timer 1 High Byte]
  // [TH1 - Timer 1 High Byte]$

  // $[TL1 - Timer 1 Low Byte]
  // [TL1 - Timer 1 Low Byte]$

  // $[Timer Restoration]
  //Restore Timer Configuration
  TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

  // [Timer Restoration]$

}

extern void
TIMER_SETUP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CKCON0 - Clock Control 0]
  /***********************************************************************
   - System clock divided by 12
   - Counter/Timer 0 uses the system clock
   - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 1 uses the clock defined by the prescale field, SCA
   ***********************************************************************/
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_12 | CKCON0_T0M__SYSCLK
      | CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
      | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
      | CKCON0_T1M__PRESCALE;
  // [CKCON0 - Clock Control 0]$

  // $[TMOD - Timer 0/1 Mode]
  /***********************************************************************
   - Mode 1, 16-bit Counter/Timer
   - Mode 0, 13-bit Counter/Timer
   - Timer Mode
   - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
   - Timer Mode
   - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
   ***********************************************************************/
  TMOD = TMOD_T0M__MODE1 | TMOD_T1M__MODE0 | TMOD_CT0__TIMER
      | TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
  // [TMOD - Timer 0/1 Mode]$

  // $[TCON - Timer 0/1 Control]
  /***********************************************************************
   - INT0 is edge triggered
   - INT1 is edge triggered
   ***********************************************************************/
  TCON |= TCON_IT0__EDGE | TCON_IT1__EDGE;
  // [TCON - Timer 0/1 Control]$

}

extern void
CMP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CMP0MX - Comparator 0 Multiplexer Selection]
  /***********************************************************************
   - External pin CMP0P.8
   - External pin CMP0N.1
   ***********************************************************************/
  uint8_t delay;

  CMP0MX = CMP0MX_CMXP__LDO_OUT | CMP0MX_CMXN__CMP0N1;
  // Delay to allow the comparator inputs to settle
  for (delay = 0; delay < 0x20; delay++)
    ;
  // [CMP0MX - Comparator 0 Multiplexer Selection]$

  // $[CMP0MD - Comparator 0 Mode]
  /***********************************************************************
   - Comparator falling-edge interrupt enabled
   - Comparator rising-edge interrupt enabled
   ***********************************************************************/
  CMP0MD |= CMP0MD_CPFIE__FALL_INT_ENABLED | CMP0MD_CPRIE__RISE_INT_ENABLED;
  // [CMP0MD - Comparator 0 Mode]$

  // $[CMP0CN0 - Comparator 0 Control 0]
  /***********************************************************************
   - Comparator enabled
   ***********************************************************************/
  CMP0CN0 |= CMP0CN0_CPEN__ENABLED;
  // [CMP0CN0 - Comparator 0 Control 0]$

}

extern void
RSTSRC_0_enter_DefaultMode_from_RESET (void)
{
  // $[RSTSRC - Reset Source]
  /***********************************************************************
   - A power-on or supply monitor reset did not occur
   - A missing clock detector reset did not occur
   - A Comparator 0 reset occurred
   ***********************************************************************/
  RSTSRC = RSTSRC_PORSF__NOT_SET | RSTSRC_MCDRSF__NOT_SET | RSTSRC_C0RSEF__SET;
  // [RSTSRC - Reset Source]$

}

extern void
EXTINT_0_enter_DefaultMode_from_RESET (void)
{

  // $[IT01CF - INT0/INT1 Configuration]
  /***********************************************************************
   - INT0 input is active low
   - Select P0.2
   - INT1 input is active low
   - Select P0.0
   ***********************************************************************/
  IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2
      | IT01CF_IN1PL__ACTIVE_LOW | IT01CF_IN1SL__P0_0;
  // [IT01CF - INT0/INT1 Configuration]$

}

extern void
TIMER16_3_enter_DefaultMode_from_RESET (void)
{
  // $[Timer Initialization]
  // Save Timer Configuration
  uint8_t TMR3CN0_TR3_save;
  TMR3CN0_TR3_save = TMR3CN0 & TMR3CN0_TR3__BMASK;
  // Stop Timer
  TMR3CN0 &= ~(TMR3CN0_TR3__BMASK);
  // [Timer Initialization]$

  // $[TMR3CN0 - Timer 3 Control]
  // [TMR3CN0 - Timer 3 Control]$

  // $[TMR3H - Timer 3 High Byte]
  // [TMR3H - Timer 3 High Byte]$

  // $[TMR3L - Timer 3 Low Byte]
  // [TMR3L - Timer 3 Low Byte]$

  // $[TMR3RLH - Timer 3 Reload High Byte]
  /***********************************************************************
   - Timer 3 Reload High Byte = 0xFF
   ***********************************************************************/
  TMR3RLH = (0xFF << TMR3RLH_TMR3RLH__SHIFT);
  // [TMR3RLH - Timer 3 Reload High Byte]$

  // $[TMR3RLL - Timer 3 Reload Low Byte]
  /***********************************************************************
   - Timer 3 Reload Low Byte = 0xE0
   ***********************************************************************/
  TMR3RLL = (0xE0 << TMR3RLL_TMR3RLL__SHIFT);
  // [TMR3RLL - Timer 3 Reload Low Byte]$

  // $[TMR3CN0]
  // [TMR3CN0]$

  // $[Timer Restoration]
  // Restore Timer Configuration
  TMR3CN0 |= TMR3CN0_TR3_save;
  // [Timer Restoration]$

}

