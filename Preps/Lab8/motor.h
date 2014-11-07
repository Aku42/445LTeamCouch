#include <stdint.h>
#include "encoder.h"

void motor_init(uint16_t period, uint16_t motorNum);

void motor_setSpeed(uint16_t speed, uint16_t motorNum);

void motor_setDuty(uint16_t duty, uint16_t motorNum);

void motor_stop(void, uint16_t motorNum);