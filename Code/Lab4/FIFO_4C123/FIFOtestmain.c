// FIFOTestMain.c
// Runs on any LM4F or TM4C microcontroller
// Test the functions provided in FIFO.c in two ways.  First, single-
// step through the first four tests of the program while watching the
// variables "letter" and "result" in the debugger.  Verify that they
// have the expected values after each line.  This test should show
// that the functions correctly implement a FIFO in the absence of
// complicating interrupts.  For the fifth test, let the program run
// for an extended period of time.  An interrupt will periodically
// fill the FIFO, and the main() function will continually empty the
// FIFO, checking that the actual received value matches the expected
// value.  This test is meant to show that interrupts at any point in
// the execution of the get() function will never cause the FIFO to
// lose data or return out of order.  Avoid single-stepping,
// especially in the main (foreground) function, because interrupts
// may continue between each step.  This may result in the FIFO
// erroneously overflowing, since it is not being emptied in the
// foreground.  To see the results of the test, look at the  LED
// (on PF3) or watch the global variables particularly "NumFullError",
// "EnteredCount", "Errors", and "LineHistogram".  The LED will be lit
// if "Errors" is non-zero, and the "LineHistogram" will give a record
// of which line of the get() function was interrupted.  The last
// index of the histogram represents the number of times that the
// interrupt missed the get() function.
// Daniel Valvano
// June 16, 2011

// Connect PF3,PF2,PF1 to logic analyzer
// PF3 high during timer ISR
// PF2 high during non critical part of main
// PF1 high during critical part of main (RxFifo_Get)


#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "PLL.h"
#include "tach.h"
#include "switch.h"
#include "motor.h"
#include "PWM.h"

  __asm unsigned long 
	Who(void){
    LDR R0, [SP,#48]               ; R0 = return address from interrupt
    bx  LR
  }

#define PF1       (*((volatile uint32_t *)0x40025008))
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

int16_t error = 0;//
uint16_t setpoint = 0;//
uint16_t k_i = 200;//needs to acutally be experimentally tested

//debug code
int main(void){ 
  int i;
  PLL_Init();                      // bus clock at 120 MHz
  SYSCTL_RCGCGPIO_R |= 0x20;       // activate port F
  while((SYSCTL_PRGPIO_R&0x20)==0){};
  GPIO_PORTF_DIR_R |= 0x0E;        // make PF3-1 output (PF3-1 built-in LEDs)
  GPIO_PORTF_AFSEL_R &= ~0x0E;     // disable alt funct on PF3-1
  GPIO_PORTF_DEN_R |= 0x0E;        // enable digital I/O on PF3-1
                                   // configure PF3-1 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFF000F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;          // disable analog functionality on PF

	motor_init(60000);
	tach_init();
	setpoint = 0;
		
	while(1){
		error = setpoint - error;//Difference in time between how long it should take to rotate between ticks and how long it actually takes
		motor_setDuty(setpoint + (k_i*error));
	}
	
}
