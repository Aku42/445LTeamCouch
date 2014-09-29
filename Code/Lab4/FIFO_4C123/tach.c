#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "tach.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
void InputCapture_Init(void(*task)(void));
void (*PeriodicTask)(void);   // user function

void tachCounter(void);

uint16_t prev_time = 0;
uint16_t curr_time = 0;
uint16_t delta_time = 0;

//Tachometer function declarations
void tach_init(void){
	InputCapture_Init(tachCounter);
}

void tachCounter(void){
	prev_time = curr_time;
	curr_time = TIMER0_TAR_R;
	delta_time = curr_time - prev_time;
}

uint16_t tach_getTimeDiff(void){
	return delta_time;
}

//Input capture functions
void InputCapture_Init(void(*task)(void)){
	long sr = StartCritical(); 
  SYSCTL_RCGCTIMER_R |= 0x01;      // activate timer0
  SYSCTL_RCGCGPIO_R |= 0x02;			 // activate port B
	while((SYSCTL_PRGPIO_R&0x0002) == 0){};// ready?
		
	GPIO_PORTB_DIR_R &= ~0x01;//setting B0 to input
	GPIO_PORTB_AFSEL_R &= ~0xFF;//disabling alternate functionality on Port B
	GPIO_PORTB_PC_R = 0;
	GPIO_PORTB_PDR_R |= 0x01;//setting pin to pull down
	GPIO_PORTB_DEN_R |= 0x01;//enabling D I/O on pin B0
	GPIO_PORTB_IM_R &= ~0x1FF;//masking interrupts while setting next few registers
	GPIO_PORTB_IS_R &= ~0x01;//setting pin B0 to interrupt on edge
	GPIO_PORTB_IBE_R &= 0x01;//setting pin B0 to interrupt on both rising and falling edges
	GPIO_PORTB_RIS_R &= ~0x1FF;//clearing any interrupt flags accidentally set earlier
	GPIO_PORTB_IM_R &= 0x01;//unmasking interrupt on pin B0
		
	PeriodicTask = task;
	TIMER0_CFG_R = TIMER_CFG_16_BIT;// set clock to 16 bit mode
	TIMER0_TAMR_R = (TIMER_TAMR_TAMR_CAP|TIMER_TAMR_TACMR|TIMER_TAMR_TACDIR);//setup timer A for input event and set count direction up
	TIMER0_CTL_R ^= TIMER_CTL_TAEVENT_BOTH;//Set interrupt to trigger on both rising and falling edges
	TIMER0_IMR_R ^= TIMER_IMR_CAEIM;//Enable capture event interrupt on timer A
	
	TIMER0_CTL_R ^= TIMER_CTL_TAEN;//Enable timer A
	EndCritical(sr);
}

void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_CAECINT;//Acknowledging interrupt occured and servicing it.
  (*PeriodicTask)();// execute user task
}