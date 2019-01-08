#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "Child.h"
#include "General.h"

FileType fileType;

/**************************************************/
/*             Read a Child from a file           */
/**************************************************/
void readChild(FILE* fp, Child* pChild)
{
	unsigned short bdata;
	if(fileType == TEXT)
	{
		//Child ID
		fscanf(fp, "%d", &pChild->id);
		fscanf(fp, "%d", &pChild->age);
	}else
	{
		fread(&bdata,2,1,fp);
		pChild->id = bdata & 0x1fff;
		pChild->age = bdata >> 13;
	}
}


/**************************************************/
/*            show a Child				           */
/**************************************************/
void showChild(const Child* pChild)
{
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}


/**************************************************/
void getChildFromUser(Child* pChild, int id)
/**************************************************/
/**************************************************/
{
	pChild->id = id;
	
	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}


/**************************************************/
/*Write a Child to the open file				*/
/**************************************************/
void writeChild(FILE* fp,const Child* pChild)
{
	if(fileType == TEXT)
		fprintf(fp,"%d %d\n",pChild->id, pChild->age);
	else
	{
		unsigned short bdata = pChild->id & 0x1fff;
		bdata |= pChild->age << 13;
		fwrite(&bdata,2,1,fp);
	}
}

//linear search
Child*	findChildById(Child** pChildList, int count, int id)
{
	Child *key_ptr,**result,key = {id,0};
	key_ptr = &key;
	qsort(pChildList,count,sizeof(Child*),childCompareById);
	result = ((Child**)bsearch(&key_ptr,pChildList,count,sizeof(Child*),childCompareById));
	if(result == NULL) return NULL;
	return *result;
}

void birthday(Child* pChild)
{
	pChild->age++;
}

int childCompareById(const void* a, const void* b)
{
	return (*(Child**)a)->id - (*(Child**)b)->id;
}

//void	releaseChild(Child* pChild)
//{
//	//nothing to release
//}
