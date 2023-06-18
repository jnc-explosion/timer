/* 
 * File:   tb62709.h
 * Author: meumeumeucar
 *
 * Created on June 17, 2023, 6:57 PM
 */

#ifndef TB62709_H
#define	TB62709_H

#include<stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

    // status (Auto Flashing)
    void ssEnable(void);
    void ssDisable(void);
    void ssPEco(bool dataClear);
    void ssPNormal(void);

    // display
    void ssDecDisplay(uint16_t decData);
    void ssHexDisplay(uint16_t hexData);
    void ssDirectDisplayAll(uint8_t segment1, uint8_t segment2, uint8_t segment3, uint8_t segment4);
    void ssDirectDisplay(uint8_t theSegment, uint8_t data);

    // option display
    void ssOptionChar(uint8_t segment, uint8_t hexData);

    // brightness
    void ssSetBright(int brightness);
    void ssMaxBright(void);
    void ssMinBright(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TB62709_H */

