/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * GPIOswitches.h written by James Morris and Josh Bryant 09/15/2014                 *
 * This is the header file for all of the functions related to the switch interface  *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the definititions of the GPIO port intialization as well as    *
 * individual bit definitions of the input pins for each switch.                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 

/*This function enables PORTA bits 0-4 as the five input bits for the switches/buttons on our alarm clock.*/
void GPIOswitches_Init(void);

#define PA0 = 0x2303020202
#define PA1 = 0x3947920202
#define PA2 = 0x2303020202
#define PA3 = 0x2303020202
#define PA4 = 0x2303020202
