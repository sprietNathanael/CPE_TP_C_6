/**
 * CPE-TP6 : tri par tas
 *
 * @file stackSorting.c
 * @brief      Useful tools to stack sorting a numeric array
 * @author     Nathanaël SPRIET, Caroline ASSAF
 * @date       27/02/2017
 */

#include "stackSorting.h"


void createStack(int* array, int arrayLength)
{
	int stackIndex = 0;
	int arrayIndex = 0;
	for(arrayIndex = 0; arrayIndex < arrayLength; arrayIndex++)
	{
		log_debug("Array[%d] = %d\n",arrayIndex, array[arrayIndex]);
		stackArray[stackIndex] = array[arrayIndex];
		checkValueAndReorder_ascending(stackIndex);
		log_debug("Stack[%d] = %d\n\n",stackIndex, stackArray[stackIndex]);
		stackIndex++;
		stackArrayLength++;
	}
	log_info("Created Stack :\n");
	printArray(stackArray, stackArrayLength);
	printTree(stackArray, stackArrayLength);
}


void checkValueAndReorder_ascending(int indexToCheck)
{
	log_debug("\tCheck value and reorder\n");
	while(!checkValue_ascending(indexToCheck))
	{
		log_debug("\tThe value stack[%d]=%d has to be reorder\n",indexToCheck,stackArray[indexToCheck]);
		indexToCheck = reorderValue_ascending(indexToCheck);
	}
}

int checkValue_ascending(int indexToCheck)
{
	log_debug("\tCheck value of stack[%d]=%d\n",indexToCheck,stackArray[indexToCheck]);
	int fatherIndex = father(indexToCheck);
	log_debug("\t\tstack[%d]=%d > (father)stack[%d]=%d ?\n",indexToCheck,stackArray[indexToCheck],fatherIndex,stackArray[fatherIndex]);
	if(stackArray[fatherIndex] > stackArray[indexToCheck])
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

int reorderValue_ascending(int indexToReorder)
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

void destroyStack()
{
	int orderedArrayIndex = 0;
	while(stackArrayLength > 0)
	{
		orderedArray[orderedArrayIndex++] = stackArray[0];
		// Replace the head of the stack by the last leaf
		stackArray[0] = stackArray[stackArrayLength-1];
		stackArrayLength--;
		orderedArrayLength++;
		checkValueAndReorder_descending(0);
	}
	printArray(orderedArray, orderedArrayLength);
	printTree(orderedArray,orderedArrayLength);
}

void checkValueAndReorder_descending(int indexToCheck)
{
	log_debug("\tCheck value and reorder\n");
	while(!checkValue_descending(indexToCheck))
	{
		log_debug("\tThe value stack[%d]=%d has to be reorder\n",indexToCheck,stackArray[indexToCheck]);
		indexToCheck = reorderValue_descending(indexToCheck);
	}
}

int checkValue_descending(int indexToCheck)
{
	log_debug("\tCheck value of stack[%d]=%d\n",indexToCheck,stackArray[indexToCheck]);
	int leftIndex = leftLeaf(indexToCheck);
	int rightIndex = rightLeaf(indexToCheck);
	log_debug("\t\tstack[%d]=%d < (left)stack[%d]=%d et (right)stack[%d]=%d  ?\n",indexToCheck,stackArray[indexToCheck],leftIndex,stackArray[leftIndex],rightIndex,stackArray[rightIndex]);
	if((leftIndex != -1 && stackArray[leftIndex] < stackArray[indexToCheck]) || (rightIndex != -1 && stackArray[rightIndex] < stackArray[indexToCheck]))
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

int reorderValue_descending(int indexToReorder)
{
	int intermediate = stackArray[indexToReorder];
	int leftIndex = leftLeaf(indexToReorder);
	int rightIndex = rightLeaf(indexToReorder);
	int newIndex;
	// Takes the smallest value between left and right, takes left if equals
	if(rightIndex == -1 || stackArray[leftIndex] <= stackArray[rightIndex])
	{
		newIndex = leftIndex;
	}
	else
	{
		newIndex = rightIndex;
	}
	log_debug("\t\tReorder value of stack[%d]=%d with stack[%d]=%d\n",indexToReorder,stackArray[indexToReorder],newIndex,stackArray[newIndex]);
	stackArray[indexToReorder] = stackArray[newIndex];
	stackArray[newIndex] = intermediate;
	log_debug("\t\tReordered : stack[%d]=%d <=> stack[%d]=%d\n",indexToReorder,stackArray[indexToReorder],newIndex,stackArray[newIndex]);
	return newIndex;
}

int leftLeaf(int currentIndex)
{
	int index = (currentIndex*2)+1;
	if(index >= stackArrayLength)
	{
		index = -1;
	}
	return(index);
}
int rightLeaf(int currentIndex)
{
	int index = (currentIndex*2)+2;
	if(index >= stackArrayLength)
	{
		index = -1;
	}
	return(index);
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

void printTree(int* tree, int treeLength)
{
	// The tree base width = the nearest higher power of two of the total element number / 2
	int treeWidth = nearestHigherPowerOfTwo(treeLength)/2;
	// The tree height = log2 of the tree width plus 1
	int treeHeight = log2_(treeWidth)+1;
	log_debug("Tree width = %d and tree height = %d\n",treeWidth, treeHeight);
	// Arrays for the different dimensions of lines
	int spaceNumber[treeHeight];
	int lineNumber[treeHeight];
	int valuesNumber[treeHeight];
	// Initialise the last line dimensions
	spaceNumber[treeHeight-1] = 0;
	lineNumber[treeHeight-1] = 0;
	valuesNumber[treeHeight-1] = treeWidth;
	// If there are more than 1 line
	if(treeHeight > 1)
	{
		// Initialise the penultimate line dimensions
		spaceNumber[treeHeight-2] = 2;
		lineNumber[treeHeight-2] = 1;
		valuesNumber[treeHeight-2] = treeWidth/2;
		int i;
		// Browse the lines from the antepenultimate
		for(i = treeHeight-3;i >= 0; i--)
		{
			// Initialise lines dimensions
			spaceNumber[i] = ((spaceNumber[i+1]+1)*2)-1;
			lineNumber[i] = spaceNumber[i+1];
			valuesNumber[i] = valuesNumber[i+1]/2;
		}
	}
	int lineCount = 0;
	int treeIndex = 0;
	// Browse lines to print
	while(lineCount != treeHeight)
	{
		int valuesCount = 0;
		int valuesMiddleSpace = spaceNumber[lineCount]+1;
		// The space between values must be at minimum 3
		if(valuesMiddleSpace < 3)
		{
			valuesMiddleSpace = 3;
		}
		// Browse values of line
		for(valuesCount = 0; treeIndex < treeLength && valuesCount < valuesNumber[lineCount]; valuesCount++)
		{
			int spaceCount = 0;
			// Print left spaces
			for(spaceCount = 0; spaceCount < spaceNumber[lineCount]; spaceCount++)
			{
				log_info(" ");
			}
			// Print value
			log_info("%d",tree[treeIndex]);
			// Print space between values
			int interSpaceCount = 0;
			for(interSpaceCount = 0; interSpaceCount < valuesMiddleSpace - (int)log10(tree[treeIndex]); interSpaceCount++)
			{
				log_info(" ");
			}
			// Increment value
			treeIndex++;
		}
		int newLineCount = 0;
		// Print new lines and links
		while(newLineCount < lineNumber[lineCount])
		{
			log_info("\n");
			// Browse values of line
			for(valuesCount = 0; valuesCount < valuesNumber[lineCount]; valuesCount++)
			{
				int interSpaceCount = 0;
				// Print left spaces
				for(interSpaceCount = 0; interSpaceCount < spaceNumber[lineCount]-(newLineCount+1); interSpaceCount++)
				{
					log_info(" ");
				}
				// Print link
				log_info("/");
				// Print space between link
				int middleSpace = ((spaceNumber[lineCount] - (interSpaceCount+1))*2)+1;
				for(interSpaceCount = 0; interSpaceCount < middleSpace; interSpaceCount++)
				{
					log_info(" ");
				}
				// Print link
				log_info("\\");
				// Print space between values
				for(interSpaceCount = 0; interSpaceCount < valuesMiddleSpace-(newLineCount+1); interSpaceCount++)
				{
					log_info(" ");
				}
			}
			newLineCount++;
		}
		lineCount++;
		log_info("\n");
	}

}

int nearestHigherPowerOfTwo(int value)
{
	// Find the nearest higher power of two
	value--;
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	value++;
	return(value);
}

int log2_(int x)
{
	// Compute the log2
	return log(x)/log(2);
}
