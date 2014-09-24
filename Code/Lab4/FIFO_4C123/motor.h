#include <stdint.h>
#include "tach.h"

void motor_init(void);

void motor_setSpeed(uint32_t rps);//maintains intended rps using tach

void motor_stop(void);