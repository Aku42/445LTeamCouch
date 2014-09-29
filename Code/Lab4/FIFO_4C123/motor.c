#include "inc/tm4c1294ncpdt.h"
#include "motor.h"
#include "PWM.h"

uint16_t DutyRPSRatio = 1000;	//needs to be checked in person. This is just a wild guess

uint16_t motorPeriod = 0;

//public function definitions
void motor_init(uint16_t period){
	motorPeriod = period;
	PWM0B_Init(motorPeriod, 0);//Initialize motor to be on pin F1 and to not start on
}

void motor_setSpeed(uint16_t speed){//input should be in rotations per second
	motor_setDuty(speed*DutyRPSRatio);
}

void motor_stop(void){
	PWM0B_Duty(0);
}

void motor_setDuty(uint16_t duty){
	//sanitizing input to saturate at limits. Note that negative values will result in full speed
	if(duty <= 2)
		duty = 2;
	if(duty >= motorPeriod)
		duty = motorPeriod-2;
	
	PWM0B_Duty(duty);
}
