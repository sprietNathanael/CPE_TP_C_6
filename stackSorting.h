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
static int orderedArray[MAX_ARRAY_LENGTH];
static int orderedArrayLength = 0;
static int stackArrayLength = 0;

/*
***************************** Functions *************************
*/


/**
 * @brief      Creates a stack.
 *
 * @param      array        The base array
 * @param[in]  arrayLength  The base array length
 */
void createStack(int* array, int arrayLength);

/**
 * @brief      Destroys a stack
 */
void destroyStack();


/**
 * @brief      Prints an array
 *
 * @param      array        The array to print
 * @param[in]  arrayLength  The array length
 */
void printArray(int* array, int arrayLength);

/**
 * @brief      Checks the current index of the stack, and reorders it if
 *             necessary, in ascending direction
 *
 * @param[in]  indexToCheck  The stack index to check
 */
void checkValueAndReorder_ascending(int indexToCheck);

/**
 * @brief      Checks the value of a stack index, in ascending direction
 *
 * @param[in]  indexToCheck  The stack index to check
 *
 * @return     1 if the index's value is greater than its father, 0 otherwise
 */
int checkValue_ascending(int indexToCheck);

/**
 * @brief      Reorders an index value, in ascending direction
 *
 * @param[in]  indexToReorder  The stack index to reorder
 *
 * @return     The new index where the old index has been reordered
 */
int reorderValue_ascending(int indexToReorder);

/**
 * @brief      Checks the current index of the stack, and reorders it if
 *             necessary, in descending direction
 *
 * @param[in]  indexToCheck  The stack index to check
 */
void checkValueAndReorder_descending(int indexToCheck);

/**
 * @brief      Checks the value of a stack index, in descending direction
 *
 * @param[in]  indexToCheck  The stack index to check
 *
 * @return     1 if the index's value is lesser than its leaves, 0 otherwise
 */
int checkValue_descending(int indexToCheck);

/**
 * @brief      Reorders an index value, in descending direction
 *
 * @param[in]  indexToReorder  The stack index to reorder
 *
 * @return     The new index where the old index has been reordered
 */
int reorderValue_descending(int indexToReorder);

/**
 * @brief      Find the left leaf of a node
 *
 * @param[in]  currentIndex  The current stack index
 *
 * @return     The index of the index's left leaf
 */
int leftLeaf(int currentIndex);

/**
 * @brief      Find the right leaf of a node
 *
 * @param[in]  currentIndex  The current stack index
 *
 * @return     The index of the index's right leaf
 */
int rightLeaf(int currentIndex);

/**
 * @brief      Find the father leaf of a node
 *
 * @param[in]  currentIndex  The current stack index
 *
 * @return     The index of the index's father leaf
 */
int father(int currentIndex);

#endif
