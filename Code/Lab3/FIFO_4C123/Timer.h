/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Timer.h written by James Morris and Josh Bryant 09/15/2014                        *
 * This is the header file for all of the functions related to the Timer and         *
 * interrupt module for the Lab 3 alarm clock.                                       *
 * This file includes the definitions of the Systick and interrupt initialization    *
 * functions as well as the ISRs for the timer interrupts.                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 /*This function enables SysTick*/
 void SysTick_Init(void);
 
 /*This function sets up the first timer interrupt which fires every second to update the clock.*/
 void secTimer_Init(void);
 
 /*This function is the ISR for the secTimer interrupt which increments the global time variables.*/
 void secTimer_handler(void);
 
 /*This function sets up the second timer interrupt which creates the sound wave for the alarm.*/
 void soundTimer_Init(void);
 
 /*This function is the ISR for the soundTimer interrupt which calls alarmsound_Task from alarmsound.c*/
 void soundTimer_handler(void);
 
 