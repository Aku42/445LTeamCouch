/*tach should run in a time based interrupt need to setup the interrupt and 
*	the interrupt handler.
*/
#include <stdint.h>

void tach_init(void);

uint16_t tach_getTimeDiff(void);