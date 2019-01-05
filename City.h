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
	Garden* garden;
	struct node* next;
}CityNODE;

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
CityNODE* 	createLinkedListForKindergartenType(const City* pCity, GardenType type);
CityNODE* 	createLinkedListForKindergartenType(const City* pCity, GardenType type);
void		releaseKindergartensLinkedList(CityNODE* list);
void 		kindergartensLinkedList(const City* pCity);

#endif
