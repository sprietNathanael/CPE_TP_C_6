/**
 * CPE-TP5 : Tri par tas
 *
 * @file main.c
 * @brief      Implement sorting of simple number array with a stack
 * @author     Nathanaël SPRIET
 * @date       27/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#define ARRAY_LENGTH 17


void printArray(int* arrayToPrint, int arrayLength);

int main()
{
	log_error("This is a error log\n");
	log_info("This is a info log\n");
	log_valid("This is a valid log\n");
	log_debug("This is a debug log\n");
	log_false("This is a false log\n");
	log_warning("This is a warning log\n");
	int arrayToSort[] = {3 , 5 , 6 , 2 , 8 , 9 , 11 , 7 , 4 , 10 , 12 , 15 , 20 , 1 , 19 , 13 , 17};
	printArray(arrayToSort, ARRAY_LENGTH);
	return 0;
}

void printArray(int* arrayToPrint, int arrayLength)
{
	int i = 0;
	log_info("Array : [");
	for(i = 0; i < arrayLength; i++)
	{
		log_info(" %d ",arrayToPrint[i]);
	}
	log_info("]\n");
}
