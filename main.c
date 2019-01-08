#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

FileType fileType;
int aa(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main(int argc, char* argv[])
{
	int a[] = {5,3,4,7,2};
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("wallak: %d\n",a[i]);
	}
	insertionSort(a,5,sizeof(int),aa);
	printf("Sorted\n");
	for(int i = 0 ; i < 5 ; i++)
		{
			printf("wallak: %d\n",a[i]);
		}

	if(argc != 2 || (*argv[1] != '1' && *argv[1] != '0'))
	{
		printf("You must enter 1 for binary file 0 for test file\nFor example %s 1\n",argv[0]);
		return -1;
	}
	fileType = (*argv[1] == '1')?BINARY:TEXT;
	City utz = { NULL,0 };
	int uReq;

	//first time read
	readCity(&utz);
	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz); 
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;
		case SORT_MENU:
			sortingMenu(&utz);
			break;
		case LINKED_LIST:
			kindergartensLinkedList(&utz);
			break;
		}
	}while (uReq!=EXIT);
	
	releaseCity(&utz);//free all allocations
	
	return EXIT_SUCCESS;
}

