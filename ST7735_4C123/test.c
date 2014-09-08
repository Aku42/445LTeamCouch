#include <stdio.h>
#include <stdint.h>
#include "test.h"

uint32_t Fixed_uDecOut2s_Test(void){
	const uint32_t testInputs[7] = {0, 1, 40, 304, 7026, 80888, 99999};
	const char correctOutputs[7][6] = {"  0.00",
																				"  0.01",
																				"  0.40",
																				"  3.04",
																				" 70.26",
																				"808.88",
																				"999.99"};
	uint8_t *testOutput;
	uint32_t i,j;
	
	i = 0;
	while(i < 7){//outer loop tests the different test cases
		j = 0;
		Fixed_uDecOut2s(testInputs[i],  (char*)testOutput);
		while(j<6){//checking characters in specific test cases
			if(testOutput[j] != correctOutputs[i][j]){
				return i;
			}
			j++;
		}
		i++;
	}
	return i;
}

uint32_t Fixed_sDecOut3s_Test(void){
	const int32_t testInputs[11] = {-9999, -8100, -102, -96, -1, 0, 7, 20, 308, 7047, 9999};
	const char correctOutputs[11][6] = {"-9.999",
																				"-8.100",
																				"-0.102",
																				"-0.096",
																				"-0.001",
																				" 0.000",
																				" 0.007",
																				" 0.020",
																				" 0.308",
																				" 7.047",
																				" 9.999"};
	uint8_t *testOutput;
	uint32_t i,j;
	
	i = 0;
	while(i < 11){//outer loop tests the different test cases
		j = 0;
		Fixed_sDecOut3s(testInputs[i],  (char*)testOutput);
		while(j<6){//checking characters in specific test cases
			if(testOutput[j] != correctOutputs[i][j]){
				return i;
			}
			j++;
		}
		i++;
	}
	return i;
}

uint32_t Fixed_uBinOut8s_Test(void){
	const uint32_t testInputs[10] = {0, 2, 64, 100, 256, 500, 512, 50000, 30000, 255997};
	const char correctOutputs[10][6] = {"  0.00",
																				"  0.01",
																				"  0.25",
																				"  0.39",
																				"  1.00",
																				"  1.95",
																				"  2.00",
																				" 19.53",
																				"117.19",
																				"999.99"};
	uint8_t *testOutput;
	uint32_t i,j;
	
	i = 0;
	while(i < 10){//outer loop tests the different test cases
		j = 0;
		Fixed_uBinOut8s(testInputs[i],  (char*)testOutput);
		while(j<6){//checking characters in specific test cases
			if(testOutput[j] != correctOutputs[i][j]){
				return i;
			}
			j++;
		}
		i++;
	}
	return i;
}