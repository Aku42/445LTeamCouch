#include <PLL.h>
#include <Timer.h>
#include <LCDscreen.h>
#inlcude <alarmsound.h>
#inlcude <GPIOswitches.h>

int main(void){
  PLL_Init();
  SysTick_Init();
  LCDscreen_Init();
  GPIOswitches_Init();
  alarmsound_Init();
  secTimer_Init();
  soundTimer_Init();
  
  //Activating port F to use as a debugging tool for watching ISR times
  SYSCTL_RCGCGPIO_R |= 0x20;       // activate port F
  while((SYSCTL_PRGPIO_R&0x20)==0){};
  GPIO_PORTF_DIR_R |= 0x1E;        // make PF3-1 output (PF3-0 built-in LEDs)
  GPIO_PORTF_AFSEL_R &= ~0x1E;     // disable alt funct on PF4-1
  GPIO_PORTF_DEN_R |= 0x1E;        // enable digital I/O on PF4-1
                                   // configure PF3-1 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFF000F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;          // disable analog functionality on PF
  BackData = 0;                    // allow time to finish activating
  
  
}