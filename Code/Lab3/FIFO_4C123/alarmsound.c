/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * alarmsound.c written by James Morris and Josh Bryant 09/15/2014                   *
 * This is the c file for all of the functions related sound output interface        *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the GPIO port intialization as well as the functions for       *
 *outputting the alarm soundwave.                                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 #include <stdint.h>
 #include "constants.h"
 
 void alarmsound_Init(void){
  //initialize port A bit 5 as an output
 }
 
 void alarmsound_On(void){
  //enable the timer interrupt for the sound wave
 }
 
 void alarmsound_Off(void){
  //disable the timer interrupt for the sound wave
 }
 
 void alarmsound_Task(void){
  //toggle PA5
 }

 