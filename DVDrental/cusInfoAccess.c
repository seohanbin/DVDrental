/* Name: cusInfoCAccess.c  ver 1.0
 * Content: 고객 정보 저장 및 참조 함수들의 정의
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER  100
#define CUS_BACKUP "cusinfo.dat"

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/* 함    수: int AddCusInfo (char * ID, char * name, char * num)
 * 기    능: cusInfo 할당 및 저장. 
 * 반    환: 성공 시 '등록된 정보의 수', 실패 시 0을 반환.
			사용후 반환값으로 오류검사 필.
 *
 */
int AddCusInfo(char * ID, char * name, char * num)
{
	if (numOfCustomer>=100)
	{
		puts("등록가능한 사용자수 초과");
		return 0;
	}

	cusList[numOfCustomer] = (cusInfo*)malloc(sizeof(cusInfo));
	strcpy(cusList[numOfCustomer]->ID, ID);
	strcpy(cusList[numOfCustomer]->name, name);
	strcpy(cusList[numOfCustomer]->phoneNum, num);
	numOfCustomer++;

	saveCUSINFO();
	return numOfCustomer;
}


/* 함    수: cusInfo * GetCusPtrByID(char * ID)
 * 기    능: 해당 ID의 정보를 담고 있는 변수의 포인터 반환 
 * 반    환: 등록 안된 ID의 경우 NULL 포인터 반환.
 *
 */
cusInfo * GetCusPtrByID(char * ID)
{
	int i = 0;
	for (i = 0; i < numOfCustomer; i++)
	{
		if (strcmp(ID, cusList[i]->ID) == 0)
		{
			return cusList[i];
		}
	}
	return NULL;
}


/* 함    수: int IsRegistID(char * ID)
 * 기    능: 가입 된 ID인지 확인. 
 * 반    환: 가입 되었으면 1, 아니면 0 반환.
 *
 */
int IsRegistID(char * ID)
{
	int i = 0;

	if (GetCusPtrByID(ID) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	//for ( i = 0; i < numOfCustomer; i++)
	//{
	//	if (!strcmp(ID,cusList[i]->ID))
	//	{
	//		printf("%s and %s", ID, cusList[i]->ID);
	//		return 1;
	//	}
	//}
	//return 0;
}


void loadCUSINFO(void) //구조체 포인터 배열
{
	int i;

	FILE* SaveData = fopen(CUS_BACKUP, "rb");
	fread(SaveData, sizeof(int), 1, &numOfCustomer);

	for ( i = 0; i < numOfCustomer; i++)
	{
		fread(cusList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}

void saveCUSINFO(void) //구포인터배열
{
	int i;

	FILE* SaveData = fopen(CUS_BACKUP, "wb");
	if (SaveData == NULL)
		return;

	fwrite(SaveData, sizeof(int), 1, &numOfCustomer);

	for ( i = 0; i < numOfCustomer; i++)
	{
		fwrite(cusList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}


/* end of file */