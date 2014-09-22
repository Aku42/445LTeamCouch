/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LCDscreen.h written by James Morris and Josh Bryant 09/15/2014                    *
 * This is the header file for all of the functions related to the LCD interface     *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the definitions of the functions that call ST7735 functions    *
 * to output to the screen, as well as the bitmap and arrays needed to draw the      *
 * clock face in display mode.                                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
 
 /*This function just calls the ST7735 Output_Init function.*/
 void LCDscreen_Init(void);
 
 /*This function draws the clock_face bitmap onto the LCD screen*/
 void LCDdraw_background(void);
 
 /*This function updates the position of the hour hand to the correct postition.*/
 void LCDupdate_hour(uint16_t old);
 
 /*This function updates the position of the min hand to the correct postition.*/
 void LCDupdate_min(uint16_t old);
 
 /*This function updates the position of the sec hand to the correct postition.*/
 void LCDupdate_sec(uint16_t old);
 
 