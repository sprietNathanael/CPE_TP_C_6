/**
 * CPE-TP6 : tri par tas
 *
 * @file stackSorting.h
 * @brief      Useful tools to stack sorting a numeric array
 * @author     Nathanaël SPRIET
 * @date       27/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

#ifndef STACK_SORTING_H
#define STACK_SORTING_H

#define MAX_ARRAY_LENGTH 255

/*
***************************** Static variables *************************
*/
static int stackArray[MAX_ARRAY_LENGTH];

/*
***************************** Functions *************************
*/
void createStack(int* array, int arrayLength);
void destroyStack(int* array, int arrayLength);

int getLeftLeaf(int* array, int arrayLength, int currentIndex);
int getRightLeaf(int* array, int arrayLength, int currentIndex);
int getFather(int* array, int arrayLength, int currentIndex);

#endif
