#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"

const char* optionStr[NofOptions] =
{
	"Exit","Read City information from file",
	"Show all Kindergartens","Show a specific Kindergarten",
	"Save City information to file","Add a Kindergarten",
	"Add a Child","Birthday to a Child",
	"Count Hova childres",
	"Sorting Menu",
	"Linked List"
};

/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option,i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for(i = 0 ; i < NofOptions; i++)
		printf("\n\t%d. %s.",i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr)
{
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*)malloc(len*sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p)
{
	if (!p)
	{
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

void insertionSort(void* arr, int length, int size, int (*comperator)(const void*,const void*))
{
	int i,j;
	void* key = malloc(size);
	if (!checkAllocation(key)) return;
	for (i = 1; i < length; i++)
	{
		key = memcpy(key,arr + i*size,size);
		for (j = i - 1; j >= 0 && (comperator(arr + j*size, key) > 0); j--)
			memmove(arr + (j + 1)*size, arr + j*size, size);
		memmove(arr + (j+1)*size, key,size);
	}
	free(key);
}

void variadicFunction(const char* word,...)
{
	va_list args;
	int num;
	const char* current;
	va_start(args,word);
	current = word;

	while(current != NULL)
	{
		num = va_arg(args,int);
		printf("%s  %d\n",current,num);
		current = va_arg(args,char*);
	}
	va_end(args);
}


