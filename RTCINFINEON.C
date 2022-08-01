/******************* OM NAMAH SHIVAYA **********************
 * rtc.c
 *
 *  Created on: Jul 7, 2022
 *      Author:venkatesh thaili
 */


#include "rtc.h"

uint8_t seconds, minutes,hours,date,month,year,oscillator,hour;

   /*********************  For this structure Read Date and time Format  *************************/
struct read_buffer
{
	    uint8_t hours;
		uint8_t minutes;
		uint8_t seconds;
		uint8_t date;
		uint8_t month;
		uint8_t year;
		uint8_t weekday;
};
struct read_buffer read_dt_time;

/********** After converting BCD to Binary Date and time Format values are store in this structure  ***********/

 struct bin_buffer
 {
	    uint8_t hours;
	    uint8_t minutes;
		uint8_t seconds;
		uint8_t date;
		uint8_t month;
		uint8_t year;
		uint8_t weekday;
};
struct bin_buffer bin;

/*FUNCTION**********************************************************************
 *
 * Function Name : RTC_WRITE
 * Description   : This function Write the current date & time format
 *
 *END**************************************************************************/

 void RTC_WRITE(uint8_t format_12_24,uint8_t am_pm, write_buffer write_dt_time)
{
	//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_FUNCTION,0X00);       //In Function Register,irrespective of current state RTCM bit = 0 in RTC Mode.//
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_FUNCTION,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 uint8_t data=0x00;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_WRITE,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 
	 

	//LPI2C0_write(PCF85263_WRITE, PCF85263_REG_STOPENABLE, 0X01);   // In STOP ENABLE Register To set STOP Bit.
	
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_STOPENABLE,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=0x01;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_WRITE,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));	
	
	
	//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RESET,0xA4);    	   // clear prescaler
	
	
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RESET,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=0xA4;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_WRITE,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));

	if(format_12_24 == 24)                                         // 24 hrs format
	{
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_OSC,0x00); 	   // oscillator register 12_24 h mode is set
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_OSC,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=0x00;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_OSC,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
		
		
		
	}
	else
	{                   // 12 hrs format
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_OSC,0x20);        // oscillator register 12_24 h mode is set
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_OSC,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=0x20;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_OSC,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	}


	if(write_dt_time.seconds > 9)		//seconds Value is greater than 9 then Perform binary to BCD operations.
	{
		seconds=binary_to_bcd(write_dt_time.seconds);
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_SC,seconds);
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_SC,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=seconds;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_SC,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	}
	else
	{
	//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_SC,write_dt_time.seconds);
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_SC,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.seconds;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_SC,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	}


	if(write_dt_time.minutes > 9)		//Minutes Value is greater than 9 then Perform binary to BCD operations.
	{
		minutes=binary_to_bcd(write_dt_time.minutes);
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MN,minutes);
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_MN,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=minutes;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_MN,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
		
	}
	else
	{
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MN,write_dt_time.minutes);
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_MN,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.minutes;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_MN,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	}


	if(format_12_24 == 12)  // 12 Hours Format
	{

        if(am_pm == 1)     // In PM Mode
         {
			if(write_dt_time.hours > 9)		//Hours Value is greater than 9 then Perform binary to BCD operations.
			{

			hours=binary_to_bcd(write_dt_time.hours);
			//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours+32);	 //For hours register set the bit 5 In PM.
			
			
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=hours+32;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
			}
			else
			{

		//	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours+32);//For hours register set the bit 5 In PM.
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.hours+32;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));			
			
			
			
			}
         }
        else            // In AM Mode
         {
			if(write_dt_time.hours > 9)		//Hours Value is greater than 9 then Perform binary to BCD operations.
			{
				hours=binary_to_bcd(write_dt_time.hours);
			//	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours);
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=hours;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));					
				
			}
			else
			{
				//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours);
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.hours;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));					
				
				
			}
         }
	  }
	else      // 24 Hours Format
	{
		if(write_dt_time.hours > 9)		//Hours Value is greater than 9 then Perform binary to BCD operations.
		{
			hours=binary_to_bcd(write_dt_time.hours);
		//	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,hours);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=hours;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));				
			

		}
		else
		{
			//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_HR,write_dt_time.hours);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_HR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.hours;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_HR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));				
			
		}
	 }


	if(write_dt_time.date > 9)		//Date Value is greater than 9 then Perform binary to BCD operations.
	{
		date=binary_to_bcd(write_dt_time.date);
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DT,date);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_DT,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=date;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_DT,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));			
		
    }
	else
	{
    	//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DT,write_dt_time.date);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_DT,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.date;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_DT,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));	
    }


	if(write_dt_time.month > 9)		//Month Value is greater than 9 then Perform binary to BCD operations.
	{
		month=binary_to_bcd(write_dt_time.month);
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MO,month);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_MO,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=month;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_MO,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));			
		
	}
	else
	{
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_MO,write_dt_time.month);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_MO,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.month;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_MO,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));			
		
	}


	if(write_dt_time.year > 9)		//Year Value is greater than 9 then Perform binary to BCD operations.
	{
		year=binary_to_bcd(write_dt_time.year);
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_YR,year);
     I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_YR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=year;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_YR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));			
		
		
	}
	else
	{
		//LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_YR,write_dt_time.year);
		
	 I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_WRITE,PCF85263_REG_RTC_YR,1,false);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
	 data=write_dt_time.year;
	 I2C_MASTER_Transmit(&I2C_MASTER_0,false,PCF85263_REG_RTC_YR,&data,1,true);
     while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));	
	}

	LPI2C0_write(PCF85263_WRITE,PCF85263_REG_RTC_DW,write_dt_time.weekday);


	LPI2C0_write(PCF85263_WRITE, PCF85263_REG_STOPENABLE, 0X00);        // To clear STOP Bit in Stop enable register.

}

 /*FUNCTION**********************************************************************
  *
  * Function Name : RTC_READ
  * Description   : This function Read the current date & time format
  *
  *END**************************************************************************/


  void RTC_READ(uint8_t format_12_24,uint8_t am_pm)
{


	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_SC,&read_dt_time.seconds,1);
	
	  I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_SC,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.seconds,1,true,true);
     while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));
	 
	read_dt_time.seconds &= ~(1<<7);		// For proper running oscillator we have clear the oscillator stop bit.	
	
	bin.seconds= bcd_to_binary(read_dt_time.seconds);


	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_MN,&read_dt_time.minutes,1);
	
    I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_MN,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.minutes,1,true,true);
     while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));
	
	
	
	read_dt_time.minutes &= ~(1<<7);    // To monitor the status of all the flags in the Flags register we have to clear this bit.
	bin.minutes= bcd_to_binary(read_dt_time.minutes);

	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_HR,&read_dt_time.hours,1);
	LPI2C0_read(PCF85263_READ,PCF85263_REG_OSC,&oscillator,1);    // Read oscillator register value.
	if (oscillator != 0)	//If Oscillator bit is 1.It is 12 hours format
	{

		bin.hours = pcf85263_bcd24h_to_bin12h(read_dt_time.hours);
	//	LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_HR,&hour,1);
      I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_HR,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&hour,1,true,true);
      while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));	
		

	}
	else					//If Oscillator bit is 0 .It is 24 hours format
	{
		bin.hours = bcd_to_binary(read_dt_time.hours & 0x3f); //because of conversation purpose hours value AND with 0x3F.
	}

	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_DT,&read_dt_time.date,1);
	
      I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_DT,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.date,1,true,true);
      while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));	
	
	bin.date=bcd_to_binary(read_dt_time.date);

	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_MO,&read_dt_time.month,1);
      I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_MO,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.month,1,true,true);
      while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));	
	
	
	
	
	bin.month=bcd_to_binary(read_dt_time.month);

	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_YR,&read_dt_time.year,1);
      I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_YR,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.year,1,true,true);
      while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));	
	
	bin.year=bcd_to_binary(read_dt_time.year);

	//LPI2C0_read(PCF85263_READ,PCF85263_REG_RTC_DW,&read_dt_time.weekday,1);
      I2C_MASTER_Transmit(&I2C_MASTER_0,true,PCF85263_READ,PCF85263_REG_RTC_DW,1,false);
      while(I2C_MASTER_IsTxBusy(&I2C_MASTER_0));
 
      I2C_MASTER_Receive(&I2C_MASTER_0,true,PCF85263_READ,&read_dt_time.weekday,1,true,true);
      while(I2C_MASTER_IsRxBusy(&I2C_MASTER_0));	
	


if(format_12_24 == 12)  // Printing  12 Hours Format
{

	  int ampm = (hour & (1<<5)) ? 1 : 0;     // Checking  hours register in AM_PM Bit. whether it is 0-> AM Mode , 1-> PM Mode.
		if(ampm == 1)     // In PM Mode
		{
			char pm[] ="PM";

			PRINTF("Time = %d",bin.hours);PRINTF(":");
			PRINTF("%02i",bin.minutes);PRINTF(":");
			PRINTF("%02i",bin.seconds);PRINTF(" ");PRINTF("%s\r\n",pm);
			PRINTF("Date = %d",bin.date);PRINTF(":");
			_month(bin.month);PRINTF(":");
			PRINTF("20%d\r\n",bin.year);
		}
		else               // In AM Mode
		{
			char pm[] ="AM";

			PRINTF("Time = %d",bin.hours);PRINTF(":");
			PRINTF("%02i",bin.minutes);PRINTF(":");
			PRINTF("%02i",bin.seconds);PRINTF(" ");PRINTF("%s\r\n",pm);
			PRINTF("Date = %d",bin.date);PRINTF(":");
			_month(bin.month);PRINTF(":");
			PRINTF("20%d\r\n",bin.year);
		}
}
else    // Printing  24 Hours Format
{

			PRINTF("Time = %d",bin.hours);PRINTF(":");
			PRINTF("%02i",bin.minutes);PRINTF(":");
			PRINTF("%02i",bin.seconds);PRINTF(" \r\n");
			PRINTF("Date = %d",bin.date);PRINTF(":");
			_month(bin.month);PRINTF(":");
			PRINTF("20%d\r\n",bin.year);
}

 /*********************  This Switch case is used for Printing weekday in string format  *************************/
	switch(read_dt_time.weekday)
	{

	case 0:PRINTF("Weekday: Sunday\r\n");
			break;
	case 1:PRINTF("Weekday: Monday\r\n");
			break;
	case 2:PRINTF("Weekday: Tuesday\r\n");
			break;
	case 3:PRINTF("Weekday: Wednesday\r\n");
			break;
	case 4:PRINTF("Weekday: Thursday\r\n");
			break;
	case 5:PRINTF("Weekday: Friday\r\n");
			break;
	case 6:PRINTF("Weekday: Saturday\r\n");
			break;
	default:PRINTF("Invalid weekday\r\n");

	}

}

  /*FUNCTION**********************************************************************
   *
   * Function Name : bcd_to_binary
   * Description   : This function convert BCD value to binary value
   *
   *END**************************************************************************/


uint8_t bcd_to_binary( uint8_t value)
{
	  uint8_t m,n;
	  m=(uint8_t)((value>>4)* 10);
	  n=value & (uint8_t)0X0F;
	  return m+n;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : binary_to_bcd
 * Description   : This function convert binary value to BCD value
 *
 *END**************************************************************************/

uint8_t binary_to_bcd( uint8_t value)
{
	  uint8_t m,n;
	  uint8_t bcd=0;

	  if(value >=10)
	  {
		  m=value/10;
		  n=value%10;
		  bcd=( uint8_t) ((m<<4) | n) ;
	  }

	  return bcd;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : pcf85263_bcd24h_to_bin12h
 * Description   : This function convert BCD value to binary value
 *
 *END**************************************************************************/

uint8_t pcf85263_bcd24h_to_bin12h(uint8_t regval)
{
	int hr = bcd_to_binary(regval);
	 if(hr>20)
	 {
	   hr-=20;
	 }
	 bool pm = regval & PCF85263_HR_PM;
	 if (hr == 12)
	 {
	   return hr;
	 }
	 else
	 {
		 if(pm)
		  {
				if(hr>12)
				{
					hr-=12;
					return hr;
				}
				else
					return hr;
			}
			else
				    return hr;
	  }

}

/*FUNCTION**********************************************************************
 *
 * Function Name : _month
 * Description   : This function converts month value equivalent in string format
 *
 *END**************************************************************************/

 /*********************  This Switch case is used for Printing month in string format  *************************/
 void _month(uint8_t _mon)
{
	switch(_mon)
	{
		case 1:
		PRINTF("Jan");
		break;
		case 2:
		PRINTF("Feb");
		break;
		case 3:
		PRINTF("Mar");
		break;
		case 4:
		PRINTF("Apr");
		break;
		case 5:
		PRINTF("May");
		break;
		case 6:
		PRINTF("Jun");
		break;
		case 7:
		PRINTF("Jul");
		break;
		case 8:
		PRINTF("Aug");
		break;
		case 9:
		PRINTF("Sep");
		break;
		case 10:
		PRINTF("Oct");
		break;
		case 11:
		PRINTF("Nov");
		break;
		case 12:
		PRINTF("Dec");
		break;
	}
}




