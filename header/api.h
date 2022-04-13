#ifndef _api_H_
#define _api_H_
#define NAME_LENGTH 10
#include  "../header/halGPIO.h"     // private library - HAL layer



extern void printSWs2LEDs(void);
extern void printArr2LEDs(char Arr[], int size, unsigned int rate);
extern void PrintStr(char str[] , int delay_ms);

#endif







