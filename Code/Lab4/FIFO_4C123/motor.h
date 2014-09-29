#include <stdint.h>
#include "tach.h"

void motor_init(uint16_t period);

void motor_setSpeed(uint16_t speed);//maintains intended rps using tach

void motor_setDuty(uint16_t duty);

void motor_stop(void);