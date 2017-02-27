/**
 * CPE-TP5 : Tri par tas
 *
 * @file main.c
 * @brief      Implement sorting of simple number array with a stack
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       27/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "stackSorting.h"
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
	printf("\n\n");
	log_info("Initial array :\n");
	int arrayToSort[] = {3 , 5 , 6 , 2 , 8 , 9 , 11 , 7 , 4 , 10 , 12 , 15 , 20 , 1 , 19 , 13 , 17};
	printArray(arrayToSort, ARRAY_LENGTH);
	createStack(arrayToSort, ARRAY_LENGTH);
	destroyStack(	);
	return 0;
}
