/* Name: rentInfoAccess.c  ver 1.1
* Content: DVD 대여 정보 저장/참조 함수들의 정의.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

//오류..
#include "rentInfoAccess.h"

#define RENT_LEN  100
#define RENT_BACKUP "rentinfo.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

/* 함    수: void AddRentList(char * ISBN, char * cusID, int rentDay)
* 기    능: 대여 정보를 저장
* 반    환: void
*
*/
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;

	saveRENTINFO();
}


/* 함    수: void PrintOutRentAllCusInfo(char * ISBN)
* 기    능: 특정 ISBN의 DVD 대여 고객 정보 출력
* 반    환: void
*
*/
void PrintOutRentAllCusInfo(char* ISBN)   // CusInfo, 고객 정보 출력
{
	int i;
	for ( i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ISBN, rentList[i].ISBN) == 0)//그냥앞에!붙일수도 있지만
		{
			printf("대여일: %d\n", rentList[i].rentDay);
			ShowCustomerInfocontinue(GetCusPtrByID(rentList[i].cusID));
		}
	}
}

/* 함    수: void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end)
* 기    능: 일정 기간 안에 이뤄진 특정 고객의 DVD 대여 정보 출력
* 반    환: void
*
*/
void PrintOutCusAllRentInfo   //RentInfo, 대여 정보 출력
(char * ID, unsigned int start, unsigned int end)
{
	int i;
	for ( i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ID, rentList[i].cusID) == 0)
		{
			if (start <= rentList[i].rentDay && rentList[i].rentDay<=end)
			{
				puts("#ShowDVDrentInfo(rentList[i]);");
				ShowDVDrentInfo(rentList[i]);
			}
		}
	}
}

void loadRENTINFO(void) //구조체 / 배열
{
	int i;

	FILE* SaveData = fopen(RENT_BACKUP, "rb");
	if (SaveData == NULL)
		return;

	fread(SaveData, sizeof(int), 1, &numOfRentCus);

	for (i = 0; i < numOfRentCus; i++)
	{
		fread(&rentList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}

void saveRENTINFO(void) //구조체 배열
{

	FILE* SaveData = fopen(RENT_BACKUP, "wb");
	if (SaveData == NULL)
		return;

	fwrite(SaveData, sizeof(int), 1, &numOfRentCus);
	fwrite(rentList, sizeof(cusInfo), numOfRentCus, SaveData);

	fclose(SaveData);

}




/* end of file */