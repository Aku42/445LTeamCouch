/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * LCDscreen.c written by James Morris and Josh Bryant 09/15/2014                    *
 * This is the c file for all of the functions related to the LCD interface          *
 * module for the Lab 3 alarm clock.                                                 *
 * This file includes the functions that call ST7735 functions to output to the      *
 * screen, as well as the bitmap and arrays needed to draw the clock face in display *
 * mode.                                                                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "constants.h"
#include "inc/tm4c123gh6pm.h"
 
void LCDscreen_Init(void){
   Output_Init();
}
 
void LCDdraw_background(void){
  //draw the clock_face bitmap using the pixel color function in ST7735.c
	ST7735_DrawBitmap(25, 120, clock_face, 80, 80);
}
 
void LCDupdate_hour(uint16_t old){
	//draw new lines overwriting the current hour line with black and then drawing a new line at arrays[current_hour]
  ST7735_Line(64,80,hour_hand_xpos[old],hour_hand_ypos[old],ST7735_Color565(0, 0, 0));
  ST7735_Line(64,80,hour_hand_xpos[current_hour],hour_hand_ypos[current_hour],clock_color);
}
 
void LCDupdate_min(uint16_t old){
  //draw new lines overwriting the current min line with black and then drawing a new line at arrays[current_min]
	ST7735_Line(64,80,min_hand_xpos[old],min_hand_ypos[old],ST7735_Color565(0, 0, 0));
  ST7735_Line(64,80,min_hand_xpos[current_min],min_hand_ypos[current_min],clock_color);
}

void LCDupdate_sec(uint16_t old){
  //draw new lines overwriting the current sec line with black and then drawing a new line at arrays[current_sec]
	ST7735_Line(64,80,min_hand_xpos[old],min_hand_ypos[old],ST7735_Color565(0, 0, 0));
  ST7735_Line(64,80,min_hand_xpos[current_sec],min_hand_ypos[current_sec],ST7735_Color565(255, 0, 0));
 }
