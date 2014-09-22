#include <stdint.h>
#include "fixed.h"

/********************Fixed_uDecOut2s_Test*******************
 Tests the functionality of the Fixed_uDecOut2s_Test
 function in the fixed.c file to verify full functionality.
 Input: 
 Output: unsigned integer number for the number of the first
	testcase that failed. Returns 7 if all test cases worked.
***********************************************************/
uint32_t Fixed_uDecOut2s_Test(void);


/********************Fixed_uDecOut3_Test********************
 Tests the functionality of the Fixed_uDecOut3_Test
 function in the fixed.c file to verify full functionality.
 Input: 
 Output: unsigned integer number for the number of the first
	testcase that failed. Returns 0 if all test cases worked.
	
Not quite sure how to test this one. The way it's set up is
a bit weird and can't be tested like the other three. You'll
just have to test this one by calling it and verifying that
the output is the correct form.
***********************************************************/
//uint32_t Fixed_uDecOut3_Test(void);

/********************Fixed_sDecOut3s_Test*******************
 Tests the functionality of the Fixed_sDecOut3s_Test
 function in the fixed.c file to verify full functionality.
 Input: 
 Output: unsigned integer number for the number of the first
	testcase that failed. Returns 11 if all test cases worked.
***********************************************************/
uint32_t Fixed_sDecOut3s_Test(void);


/********************Fixed_uBinOut8s_Test*******************
 Tests the functionality of the Fixed_uBinOut8s_Test
 function in the fixed.c file to verify full functionality.
 Input: 
 Output: unsigned integer number for the number of the first
	testcase that failed. Returns 10 if all test cases worked.
***********************************************************/
uint32_t Fixed_uBinOut8s_Test(void);
