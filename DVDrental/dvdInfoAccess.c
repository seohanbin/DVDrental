/* Name: cusInfoCAccess.c  ver 1.0
 * Content: �� ���� ���� �� ���� �Լ����� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD  100

static dvdInfo * dvdList[MAX_DVD]; // �����͹迭 => �����ʿ�
static int numOfDVD=0;

/* ��    ��: int AddCusInfo (char * ID, char * name, char * num)
 * ��    ��: cusInfo �Ҵ� �� ����. 
 * ��    ȯ: ���� �� '��ϵ� ������ ��', ���� �� 0�� ��ȯ.
			����� ��ȯ������ �����˻� ��.
 *
 */
int AddDVDInfo(char * isbn, char * title, int * genre)
{
	if (numOfDVD>=MAX_DVD)
	{
		puts("��ϰ����� ����� �ʰ�");
		return 0;
	}

	dvdList[numOfDVD] = (dvdInfo*)malloc(sizeof(dvdInfo));
	strcpy(dvdList[numOfDVD]->ISBN, isbn);
	strcpy(dvdList[numOfDVD]->title, title);
	//strcpy(dvdList[numOfDVD]->genre, genre);
	dvdList[numOfDVD]->genre = *genre;
	dvdList[numOfDVD]->numOfRentCus = 0;
	dvdList[numOfDVD]->rentState = RETURNED;
	numOfDVD++;
	return numOfDVD;
}


/* ��    ��: cusInfo * GetCusPtrByID(char * ID)
 * ��    ��: �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ 
 * ��    ȯ: ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
 *
 */
dvdInfo * GetDVDPtrByID(char * ISBN)
{
	int i = 0;
	for (i = 0; i < numOfDVD; i++)
	{
		if (strcmp(ISBN, dvdList[i]->ISBN) == 0)
		{
			return dvdList[i];	
		}
	}
	return NULL;
}


/* ��    ��: int IsRegistID(char * ID)
 * ��    ��: ���� �� ID���� Ȯ��. 
 * ��    ȯ: ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ.
 *
 */
int IsRegistDVD(char * ISBN)
{
	int i = 0;

	if (GetDVDPtrByID(ISBN) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	//for ( i = 0; i < numOfDVD; i++)
	//{
	//	if (!strcmp(ISBN,dvdList[i]->ISBN))
	//	{
	//		return 1;
	//	}
	//}
	//return 0;
}




/* end of file */