#include <stdio.h>

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
