#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "fixed.h"

void Fixed_uDecOut2s(uint32_t n,  char *string){
	int32_t i;
	for(i = 5; i >= 0; i--){
		if(i == 3){
			string[i] = '.';
		}
		else{
			string[i] = (n%10) + 48;
			n = n/10;
		}
	}
}

void Fixed_uDecOut2(uint32_t n){
	uint8_t *str;
	if(n > 99999){
		str = (uint8_t*)"***.**";
	}
	else{
		Fixed_uDecOut2s(n, (char*)str);
	}
	ST7735_OutString(str);
}

void Fixed_uDecOut3(uint32_t n){
	uint8_t *str;
	int32_t i;
	if(n > 99999){
		str = (uint8_t*)"**.***";
	}
	else{
		for(i = 5; i >= 0; i--){
			if(i == 2){
				str[i] = '.';
			}
			else{
				str[i] = (n%10) + 48;
				n = n/10;
			}
		}
	}
	ST7735_OutString(str);
}

void Fixed_sDecOut3s(int32_t n, char *string){
	int32_t i, j;
	if (n >= 0){
		j = 4;
	}
	else{
		j = 5;
	}
	for(i = j; i >= 0; i--){
		if(i == j-3){
			string[i] = '.';
		}
		else{
			string[i] = (n%10) + 48;
			n = n/10;
		}
	}
	if(n < 0){
		string[0] = '-';
	}
}

void Fixed_sDecOut3(int32_t n){
	uint8_t *str;
	if((n > 9999)||(n < -9999)){
		str = (uint8_t*)"*.***";
	}
	else{
		Fixed_sDecOut3s(n, (char*)str);
	}
	ST7735_OutString(str);
}

void Fixed_uBinOut8s(uint32_t n,  char *string){
	int32_t i;
	n = ((100*n)+128)/256;
	for(i = 5; i >= 0; i--){
		if(i == 3){
			string[i] = '.';
		}
		else{
			string[i] = (n%10) + 48;
			n = n/10;
		}
	}
}

void Fixed_uBinOut8(uint32_t n){
	uint8_t *str;
	if(n >= 256000){
		str = (uint8_t*)"***.**";
	}
	else{
		Fixed_uBinOut8s(n, (char*)str);
	}
	ST7735_OutString(str);
}
