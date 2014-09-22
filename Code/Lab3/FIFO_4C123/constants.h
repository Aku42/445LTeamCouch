/* constants.h
   This file contains all of the definitions of the global variables for lab 3. */

const extern uint16_t clock_face[6400];   //the array containing the background bitmap
const extern uint8_t min_hand_xpos[60];  //contains the x value of the ending position for each minute/second hand value
const extern uint8_t min_hand_ypos[60];  //contains the y value of the ending position for each minute/second hand value
const extern uint8_t hour_hand_xpos[48]; //contains the x value of the ending position for each hour hand value
const extern uint8_t hour_hand_ypos[48]; //contains the y value of the ending position for each hour hand value
const extern uint16_t clock_color; //color of the clock face, minute and hour hands

extern uint16_t current_sec; //current seconds value
extern uint16_t current_min; //current minutes value
extern uint16_t current_hour; //current hours value
extern uint8_t sec_flag; //seconds changed flag
extern uint8_t min_flag; //minutes changed flag
extern uint8_t hour_flag; //hours changed flag
extern uint16_t alarm_sec; //seconds alarm value
extern uint16_t alarm_min; //minutes alarm value
extern uint16_t alarm_hour; //hours alarm value
extern uint8_t alarm_flag; //alarm enabled flag
