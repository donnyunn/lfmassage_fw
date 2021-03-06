/*
 * driver.h
 *
 *  Created on: 2021. 10. 12.
 *      Author: donny
 */

#ifndef INC_DRIVER_H_
#define INC_DRIVER_H_

void addTimCnt(void);
bool getTimeout(void);
void setBtnPlus(bool pressed);
void setBtnMode(bool pressed);
void setBtnMinus(bool pressed);
bool getBtnPlus(void);
bool getBtnMode(void);
bool getBtnMinus(void);
void setLedRed(bool on);
void setLedGrn(bool on);
void setLedBlu(bool on);
void setIrLed(bool on);
void toggleBuzz(void);
void offBuzz(void);
void toggleSwitch(void);
void offSwitch(void);
void pulseNeg(int width);
void pulsePos(int width);
void pulseBoth(int width);
void charge(uint32_t mv);

uint32_t getSens(void);
void driver_make_shock(int pw, uint32_t amp);
void driver_updateSens(uint32_t mV);

#endif /* INC_DRIVER_H_ */
