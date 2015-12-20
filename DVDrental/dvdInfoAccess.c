/* Name: cusInfoCAccess.c  ver 1.0
 * Content: 고객 정보 저장 및 참조 함수들의 정의
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD  100

static dvdInfo * dvdList[MAX_DVD]; // 포인터배열 => 말록필요
static int numOfDVD=0;

/* 함    수: int AddCusInfo (char * ID, char * name, char * num)
 * 기    능: cusInfo 할당 및 저장. 
 * 반    환: 성공 시 '등록된 정보의 수', 실패 시 0을 반환.
			사용후 반환값으로 오류검사 필.
 *
 */
int AddDVDInfo(char * isbn, char * title, int * genre)
{
	if (numOfDVD>=MAX_DVD)
	{
		puts("등록가능한 디비디수 초과");
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


/* 함    수: cusInfo * GetCusPtrByID(char * ID)
 * 기    능: 해당 ID의 정보를 담고 있는 변수의 포인터 반환 
 * 반    환: 등록 안된 ID의 경우 NULL 포인터 반환.
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


/* 함    수: int IsRegistID(char * ID)
 * 기    능: 가입 된 ID인지 확인. 
 * 반    환: 가입 되었으면 1, 아니면 0 반환.
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