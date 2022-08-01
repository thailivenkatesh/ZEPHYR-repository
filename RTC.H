/*
 * rtc.h
 *
 *  Created on: Aug 10, 2021
 *      Author:
 */


#ifndef RTC_H__
#define RTC_H__

#include <eeprom_i2c.h>
#include "utils/nxp_console.h" /* PRINTF */

#define PCF85263_REG_RTC_SC	    0x01	/* Seconds */
#define PCF85263_REG_RTC_MN	    0x02	/* Minutes */
#define PCF85263_REG_RTC_HR	    0x03	/* Hours */
#define PCF85263_REG_RTC_DT   	0x04	/* Day of month 1-31 */
#define PCF85263_REG_RTC_DW  	0x05	/* Day of week 0-6 */
#define PCF85263_REG_RTC_MO 	0x06	/* Month 1-12 */
#define PCF85263_REG_RTC_YR 	0x07	/* Year 0-99 */
#define PCF85263_REG_OSC	    0x25    /* oscillator register   value is 0x20 am_pm flag is set   12 hours format is selected*/
#define PCF85263_REG_RESET	    0x2F	/* Reset command */
#define PCF85263_REG_STOPENABLE 0x2E    /* (0X00 value) */
#define PCF85263_REG_FUNCTION	0x28    /* RTCM is 0*/
#define PCF85263_WRITE          0xA2    /* RTC Write Address */
#define PCF85263_READ           0xA3	/* RTC Read Address */
#define PCF85263_HR_PM          1<<5	/* SET the 5th bit */

  /*********************  For this structure Write Date and time Format  *************************/
typedef struct
{
			  uint8_t hours;
			  uint8_t minutes;
			  uint8_t seconds;
			  uint8_t date;
			  uint8_t month;
			  uint8_t year;
			  uint8_t weekday;

}write_buffer;


/*!
 * @brief This function Write the  values of a  Specific registers.
 *
 * @param format_12_24: It specifies time format whether 12 hours mode nor 24 hours mode.
 * @param am_pm: It specifies whether time zone is AM or PM.
 * @param write_dt_time: it writes the specified time & date in write_buffer structure through flag
 * @return Nothing
 */
void RTC_WRITE(uint8_t format_12_24,uint8_t am_pm, write_buffer write_dt_time);

/*!
 * @brief This function Read the  values from a  Specific registers.
 *
 * @param format_12_24: It specifies time format whether 12 hours mode nor 24 hours mode.
 * @param am_pm: It specifies whether time zone is AM or PM.
 * @return Nothing
 */
void RTC_READ(uint8_t format_12_24,uint8_t am_pm);

/*!
 * @brief This function convert BCD value to binary value .
 *
 * @param value: It specifies BCD value.
 * @return Binary value
 */
uint8_t bcd_to_binary( uint8_t value);

/*!
 * @brief This function convert binary value to BCD value .
 *
 * @param value: It specifies Binary value.
 * @return BCD value
 */
uint8_t binary_to_bcd( uint8_t value);

/*!
 * @brief This function convert BCD value to binary value.
 *
 * @param regval: It specifies BCD value.
 * @return Binary value
 */
uint8_t pcf85263_bcd24h_to_bin12h(uint8_t regval) ;

/*!
 * @brief This function converts month value equivalent in string format
 *
 * @param _mon:It specifies given month value
 * @return Nothing
 */
void _month(uint8_t _mon);

#endif /* RTC_H_ */



/*********************  RTC  Flags *************************/
#if		RTCMODULE

#define TIME_FORMAT                   24     /* time format 12 -> 12 hours mode    time format 24 -> 24 hours mode */
#define    AM_PM                      1      /* AM_PM  flag value is 0 in AM mode, 1 is PM mode.*/
#define    READ                       1      /* For Reading data  this bit is 1    other wise this bit is 0 */
#define    WRITE                      0      /* For Writing data  this bit is 1    other wise this bit is 0 */
write_buffer write= {4,53,00,25,07,22,2};    /* HH:MM:SS:DT:MO:YR:DAY */

/*********************  End of RTC Flags  *****************/
void LPI2C_RTC_Test();

void LPI2C_RTC_Test() {

#if WRITE
	RTC_WRITE(TIME_FORMAT, AM_PM, write);
#endif

#if READ
	RTC_READ(TIME_FORMAT, AM_PM);
#endif
}


main(){
	RTC_WRITE(TIME_FORMAT, AM_PM, write);
	while(1){
		RTC_READ(TIME_FORMAT, AM_PM);
	}
