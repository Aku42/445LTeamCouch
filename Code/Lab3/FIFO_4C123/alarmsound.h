/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * alarmsound.h written by James Morris and Josh Bryant 09/15/2014                   *
 * This is the header file for all of the functions related sound output interface   *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the definititions of the GPIO port and intialization           *
 * the functions for outputting the alarm soundwave.                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 /*This function initializes PortA bit 5 as the output bit for the sound wave.*/
 void alarmsound_Init(void);
 
 /*This function enables the timer interrupt for the alarm sound wave.*/
 void alarmsound_On(void);
 
 /*This function disables the timer interrupt for the alarm sound wave.*/
 void alarmsound_Off(void);
 
 /*This function is called from the ISR and toggles PA5 to create the sound wave.*/
 void alarmsound_Task(void);

