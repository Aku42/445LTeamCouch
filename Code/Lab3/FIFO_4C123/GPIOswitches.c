/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * GPIOswitches.c written by James Morris and Josh Bryant 09/15/2014                 *
 * This is the .c file for all of the functions related to the switch interface      *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the GPIO port intialization.                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 #include <stdint.h>
 #include "constants.h"
 #include "inc\tm4c123gh6pm.h"
 
 void GPIOswitches_Init(void){
	 uint16_t BackData;
 //initialize portD bits 0-4 as inputs for the switches
  SYSCTL_RCGCGPIO_R |= 0x00000002;  // 1) activate clock for Port F
  BackData = SYSCTL_RCGCGPIO_R;        // allow time for clock to start
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTB_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTB_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTB_DIR_R = 0x00;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTB_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTB_PUR_R = 0x03;          // enable pull-up on PF0 and PF4
  GPIO_PORTB_DEN_R = 0x03;          // 7) enable digital I/O on PF4-0
  BackData = 0;                    // allow time to finish activating
 }

 
 