/* Name: screenOut.c  ver 1.0
 * Content: 콘솔 출력을 위한 함수 정의
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"
#include "rentInfo.h"
//히스토리호출시아이디를 통해 커스인포에 액세스필요..
#include "cusInfoAccess.h"


/* 프로그램 사용을 위한 메뉴 */
void ShowMenu(void)
{
    system("cls");   //stdlib.h
    
    printf("━━━━━ 메  뉴 ━━━━━━━ \n");
    printf(" 1. 신규가입 \n");
    printf(" 2. 고객검색 \n");
	printf("━━━━━━━━━━━━━━━━ \n");

	printf(" 3. DVD등록 \n");
	printf(" 4. DVD찾기 \n");
	printf("━━━━━━━━━━━━━━━━ \n");

	printf(" 5. DVD 대여 \n");
	printf(" 6. DVD 반납 \n");
	printf("━━━━━━━━━━━━━━━━ \n");

    printf(" 7. DVD 대여고객 전체출력 \n");
	printf(" 8. 종료 \n");
    printf("━━━━━━━━━━━━━━━━ \n");
    printf("선택》 ");
}


/* 고객 개인의 기본 정보 출력 */
void ShowCustomerInfo(cusInfo * pCus)
{
    
    printf("┏━━━━━━━━━━━━━━━━ \n");
    printf("┃ ▶ ID: %s \n", pCus->ID);
    printf("┃ ▶ 이름: %s \n", pCus->name);
    printf("┃ ▶ 전화번호: %s \n", pCus->phoneNum);
    printf("┗━━━━━━━━━━━━━━━━ \n\n");
    
	system("pause");
	//system("cls");   //stdlib.h
	//히스토리보여줄때 있으면 안됨..
}

void ShowCustomerInfocontinue(cusInfo * pCus)
{

	printf("┏━━━━━━━━━━━━━━━━ \n");
	printf("┃ ▶ ID: %s \n", pCus->ID);
	printf("┃ ▶ 이름: %s \n", pCus->name);
	printf("┃ ▶ 전화번호: %s \n", pCus->phoneNum);
	printf("┗━━━━━━━━━━━━━━━━ \n\n");

	//system("pause");
	//system("cls");   //stdlib.h
	//히스토리보여줄때 있으면 안됨..
}

/* DVD 기본 정보 출력 */
void ShowDVDInfo(dvdInfo * pCus)
{

	printf("┏━━━━━━━━━━━━━━━━ \n");
	printf("┃ ▶ ISBN: %s \n", pCus->ISBN);
	printf("┃ ▶ title: %s \n", pCus->title);
	printf("┃ ▶ genre: "); ShowGenre(pCus->genre); puts("");
	printf("┗━━━━━━━━━━━━━━━━ \n\n");

	system("pause");
	system("cls");   //stdlib.h

}

void ShowDVDrentInfo(dvdRentInfo pRinfo)
{

	printf("┏━━━━━━━━━━━━━━━━ \n");
	printf("┃ ▶ ISBN: %s \n", pRinfo.ISBN);
	printf("┃ ▶ 대여일: %d\n", pRinfo.rentDay);
	printf("┗━━━━━━━━━━━━━━━━ \n\n");

}

//void ShowRentHistory(dvdInfo * pCus)
//{//여기다가 히스토리 예정
//
//	int i;
//	for ( i = 0; i < pCus->numOfRentCus ; i++)
//	{
//		printf("대여일: %d \n", pCus->rentList[i].rentDay);
//		ShowCustomerInfocontinue(GetCusPtrByID(pCus->rentList[i].cusID));
//		printf("━━━━━━━━━━━━━━━━ \n");
//	}
//
//
//}


//2가지 방식 반환가능. 문자열출력void, 문자열반환char*
void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		fputs("액션", stdout);
		break;
	case COMIC:
		fputs("코믹", stdout);
		break;
	case SF:
		fputs("과학", stdout);
		break;
	case ROMANTIC:
		fputs("로맨틱", stdout);
		break;
	}
}




/* end of file */