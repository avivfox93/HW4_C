#ifndef __PROTOTYPE__
#define __PROTOTYPE__

typedef enum
{
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_MENU,
	NofOptions
} MenuOptions;

typedef enum
{
	SORT_KINDERGARTEN_BY_NAME,
	SORT_KINDERGARTEN_BY_TYPE,
	SORT_CHILDREN_BY_ID,
	NofSorts
} SortType;

typedef enum
{
	TEXT,
	BINARY
} FileType;

int		menu();
char*	getStrExactLength(char* inpStr);
int		checkAllocation(const void* p);
void 	insertionSort(void** arr, int length, int (*comperator)(const void*,const void*));
void 	variadicFunction(const char* word,...);

extern 	FileType fileType;


#endif
