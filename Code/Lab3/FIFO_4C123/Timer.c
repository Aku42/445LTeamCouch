/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Timer.c written by James Morris and Josh Bryant 09/15/2014                        *
 * This is the c file for all of the functions related to the Timer and              *
 * interrupt module for the Lab 3 alarm clock.                                       *
 * This file includes the implementations of the Systick and interrupt               *
 * initialization functions as well as the ISRs for the timer interrupts.            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 #include <stdint.h>
 #include "constants.h"
 #include "alarmsound.h"
 #include "inc/tm4c123gh6pm.h"
  
 uint16_t current_sec_frac; //current 1/8th seconds value

 void SysTick_Init(void){
   //enable systick running at the system clock
	 NVIC_ST_RELOAD_R = 0x01;  //Program value in the STRELOAD register (
	 NVIC_ST_CURRENT_R = 0x00; //Clear STCURRENT register by writing any value to it
	 NVIC_ST_CTRL_R = 0x04;    //Configure the STCTRL register for required operation
 }
 
 void secTimer_Init(void){
   //enable systick timer interrupt to fire 8 times a second (clock goes too fast for one second interrutps)
	 NVIC_ST_RELOAD_R = 0x00989680;  //change to however many clock cycles equals 1 second
	 NVIC_ST_CURRENT_R = 0x00; //Clear STCURRENT register by writing any value to it
	 NVIC_ST_CTRL_R = 0x07;    //COnfigure STCTRL register to run of system clock, and enable interrupts and countdown
 }
 
 void secTimer_handler(void){
   //increment current_seconds and current_min/hours if needed
	 //TODO: Acknowledge interrupt.
	 current_sec_frac++;
	 if(current_sec_frac > 7){
	   current_sec++;
		 sec_flag = 1;
		 current_sec_frac = 0;
   }
	 if(current_sec>59){
		 current_sec = 0;
		 current_min++;
		 min_flag = 1;
	   if(current_min/15 == 0){
		   if(current_min>59){
			   current_min = 0;
		   }
		   current_hour++;
		   hour_flag = 1;
			 if(current_hour > 95){
				 current_hour = 0;
			 }
		 }
	 }
 }
 
 void soundTimer_Init(void){
   //enable a timer interrupt running at the frequency needed for a good sound wave
 }
 
 void soundTimer_handler(void){
	 //TODO: Acknowledge Interrupt.
   alarmsound_Task();
 }

 