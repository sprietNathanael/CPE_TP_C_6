/**
 * CPE-TP6 : tri par tas
 *
 * @file stackSorting.c
 * @brief      Useful tools to stack sorting a numeric array
 * @author     Nathanaël SPRIET
 * @date       27/02/2017
 */

#include "stackSorting.h"

int createStack(int* array, int arrayLength)
{
	int stackIndex = 0;
	int arrayIndex = 0;
	for(arrayIndex = 0; arrayIndex < arrayLength; arrayIndex++)
	{
		log_debug("Array[%d] = %d\n",arrayIndex, array[arrayIndex]);
		stackArray[stackIndex] = array[arrayIndex];
		checkValueAndReorder(stackIndex);
		log_debug("Stack[%d] = %d\n\n",stackIndex, stackArray[stackIndex]);
		stackIndex++;
		stackArrayLength++;
	}
	log_info("Created Stack :\n");
	printArray(stackArray, stackArrayLength);
}

void checkValueAndReorder(int indexToCheck)
{
	log_debug("\tCheck value and reorder\n");
	while(!checkValue(indexToCheck))
	{
		log_debug("\tThe value stack[%d]=%d has to be reorder\n",indexToCheck,stackArray[indexToCheck]);
		indexToCheck = reorderValue(indexToCheck);
	}
}

int checkValue(int indexToCheck)
{
	log_debug("\tCheck value of stack[%d]=%d\n",indexToCheck,stackArray[indexToCheck]);
	int fatherIndex = father(indexToCheck);
	log_debug("\t\tstack[%d]=%d > (father)stack[%d]=%d ?\n",indexToCheck,stackArray[indexToCheck],fatherIndex,stackArray[fatherIndex]);
	if(stackArray[fatherIndex] != -1 && stackArray[fatherIndex] > stackArray[indexToCheck])
	{
		log_false("\t\tNo !\n");
		return 0;
	}
	else
	{
		log_valid("\t\tYes !\n");
		return 1;
	}
}

int reorderValue(int indexToReorder)
{
	int intermediate = stackArray[indexToReorder];
	int fatherIndex = father(indexToReorder);
	log_debug("\t\tReorder value of stack[%d]=%d with father : stack[%d]=%d\n",indexToReorder,stackArray[indexToReorder],fatherIndex,stackArray[fatherIndex]);
	stackArray[indexToReorder] = stackArray[fatherIndex];
	stackArray[fatherIndex] = intermediate;
	log_debug("\t\tReordered : stack[%d]=%d <=> stack[%d]=%d\n",indexToReorder,stackArray[indexToReorder],fatherIndex,stackArray[fatherIndex]);
	return fatherIndex;
}

int father(int currentIndex)
{
	return((currentIndex-1)/2);
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
