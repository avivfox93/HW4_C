#include <stdio.h>
#include <stdlib.h>

#include "City.h"
#include "Kindergarten.h"
#include "General.h"

FileType fileType;

const char* sortingStr[NofSorts] =
{
		"Sort Kindergartens By Name",
		"Sort Kindergarten By Type",
		"Sort Children By ID"
};

void readCity(City* pCity)
{
	if (pCity->pGardenList != NULL) {
		releaseCity(pCity);
		pCity->count = 0;
	}
	pCity->pGardenList = readAllGardensFromFile((fileType == TEXT)?DATA_FILE:BIN_FILE, &pCity->count);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void	showCityGardens(City* pCity)
{
	showAllGardens(pCity->pGardenList, pCity->count);
}

void	showSpecificGardenInCity(City* pCity)
{
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity)
{
	writeGardensToFile(pCity->pGardenList, pCity->count, (fileType == TEXT)?DATA_FILE:BIN_FILE);
}

void cityAddGarden(City* pCity)
{
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL)//Allocation error
		printf("Error adding kindergarten\n");
}

void	addChildToSpecificGardenInCity(City* pCity)
{
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void	birthdayToChild(City* pCity)
{
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int	countChova(City* pCity)
{
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++)
	{
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void	releaseCity(City* pCity)
{
	release(pCity->pGardenList, pCity->count);
}

void sortingMenu(City* pCity)
{
	int option,i;
	do
	{
		printf("\n==========================");
		printf("\nSelect:\n");
		for(i = 0 ; i < NofSorts; i++)
			printf("\n\t%d. %s.",i, sortingStr[i]);
		printf("\n");
		scanf("%d", &option);
	}while(option >= NofSorts || option < 0);
	if(option == SORT_CHILDREN_BY_ID)
		for(i = 0 ; i < pCity->count ; i++)
			insertionSort((void*)pCity->pGardenList[i]->childPtrArr,
					pCity->pGardenList[i]->childCount,childCompareById);
	else
		insertionSort((void*)pCity->pGardenList,pCity->count,
				(option == SORT_KINDERGARTEN_BY_NAME)?compareGardenByName:compareGardenByType);
}

Node* createLinkedListForKindergartenType(const City* pCity, GardenType type)
{
	int i;
	Node *result,*temp,*last = NULL;
	if(!checkAllocation((result = (Node*)calloc(1,sizeof(Node)))))
		return NULL;
	last = result;
	for(i = 0 ; i < pCity->count ; i++)
	{
		if(pCity->pGardenList[i]->type == type)
		{
			if(result->data == NULL)
				result->data = pCity->pGardenList[i];
			else if(!checkAllocation((temp = (Node*)malloc(sizeof(Node)))))
					return result;
			else
			{
				temp->data = pCity->pGardenList[i];
				temp->next = NULL;
				last->next =  temp;
				last = temp;
			}
		}
	}
	return result;
}

void displayKindergartensFromList(const Node* list)
{
	int i;
	for(i = 1 ; list != NULL ; list = list->next, i++)
	{
		printf("\nKindergarten %d:\n",i);
		showGarden((Garden*)list->data);
		printf("\n");
	}
}

void releaseKindergartensLinkedList(Node* list)
{
	for(;list != NULL ; list = list->next)
		free(list);
}

void kindergartensLinkedList(const City* pCity)
{
	Node* list;
	GardenType type;
	type = getTypeOption();
	list = createLinkedListForKindergartenType(pCity,type);
	displayKindergartensFromList(list);
	releaseKindergartensLinkedList(list);
}
