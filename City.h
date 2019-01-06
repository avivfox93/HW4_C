#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"

#define DATA_FILE "DataFile.txt"
#define BIN_FILE "DataFile.bin"

typedef struct
{
	Garden** pGardenList;
	int count;
}City;

typedef struct node
{
	void* data;
	struct node* next;
}Node;

void		readCity(City* pCity);
void		showCityGardens(City* pCity);
void		showSpecificGardenInCity(City* pCity);
void		saveCity(City* pCity);
void		cityAddGarden(City* pCity);
void		addChildToSpecificGardenInCity(City* pCity);
void		birthdayToChild(City* pCity);
int			countChova(City* pCity);
void 		sortingMenu(City* pCity);
void		releaseCity(City* pCity);
Node* 		createLinkedListForKindergartenType(const City* pCity, GardenType type);
void		releaseKindergartensLinkedList(Node* list);
void 		kindergartensLinkedList(const City* pCity);

#endif
