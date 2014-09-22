#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "ST7735.h"
#include "fixed.h"

void Fixed_uDecOut2s(uint32_t n,  char *string){
	int32_t i,j;
	if(((j=(int)log10((double)n))<3)){
		j = 2;
	}
	j += 1;
	for(i = 5; i >= 5-j; i--){
		if(i == 3){
			string[i] = '.';
		}
		else{
			string[i] = (n%10) + 0x30;
			n = n/10;
		}
	}
}

void Fixed_uDecOut2(uint32_t n){
	uint8_t *str;
	str = (uint8_t*)malloc(sizeof(uint8_t)*7);
	str = (uint8_t*)strcpy((char*)str, "      ");
	if(n > 99999){
		str = (uint8_t*)strcpy((char*)str, "***.**");
	}
	else{
		Fixed_uDecOut2s(n, (char*)str);
	}
	printf((char*)str);
	free(str);
}

void Fixed_uDecOut3(uint32_t n){
	uint8_t *str;
	int32_t i,j;
	str = (uint8_t*)malloc(sizeof(uint8_t)*7);
	str = (uint8_t*)strcpy((char*)str, "      ");
	if(n > 99999){
		str = (uint8_t*)strcpy((char*)str, "**.***");
	}
	else{
		if((j=(int)log10((double)n))<4){
		  j = 3;
	  }
		j++;
		for(i = 5; i >= 5-j; i--){
			if(i == 2){
				str[i] = '.';
			}
			else{
				str[i] = (n%10) + 48;
				n = n/10;
			}
		}
	}
	printf((char*)str);
	free(str);
}

void Fixed_sDecOut3s(int32_t n, char *string){
	int32_t i, j;
	if((j=(int)log10((double)n))<3){
		j=3;
	}
	j++;
	if(n < 0){
		string[0] = '-';
	}
	for(i = 5; i >= 5-j; i--){
		if(i == 2){
			string[i] = '.';
		}
		else{
			string[i] = (abs(n)%10) + 48;
			n = n/10;
		}
	}
}

void Fixed_sDecOut3(int32_t n){
	uint8_t *str;
	str = (uint8_t*)malloc(sizeof(uint8_t)*7);
	str = (uint8_t*)strcpy((char*)str, "      ");
	if((n > 9999)||(n < -9999)){
		str = (uint8_t*)strcpy((char*)str, " *.***");
	}
	else{
		Fixed_sDecOut3s(n, (char*)str);
 	}
	printf((char*)str);
	free(str);
}

void Fixed_uBinOut8s(uint32_t n,  char *string){
	int32_t i,j;
	n = ((100*n)+128)/256;
	if((j=(int)log10((double)n))<3){
		j=2;
	}
	j++;
	for(i = 5; i >= 5-j; i--){
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
	str = (uint8_t*)malloc(sizeof(uint8_t)*7);
	str = (uint8_t*)strcpy((char*)str, "      ");
	if(n >= 255998){
		str = (uint8_t*)strcpy((char*)str, "***.**");
	}
	else{
		Fixed_uBinOut8s(n, (char*)str);
	}
	printf((char*)str);
	free(str);
}
