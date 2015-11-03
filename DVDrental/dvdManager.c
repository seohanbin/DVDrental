/* Name: cusManager.c  ver 1.0
* Content: dvd 관련 업무 처리 함수.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

/* 함    수: void RegistCustomer(void)
* 기    능: 신규 회원 가입.
* 반    환: void
*
*/
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;      // 장르


	fputs("Isbn 입력: ", stdout);
	gets(ISBN);
	if (IsRegistDVD(ISBN))
	{
		puts("이미 존재하는 ISBN..재시도 필요");
		system("pause");
		return;
	}

	fputs("타이틀 입력: ", stdout);
	gets(title);


	fputs("장르 입력(액션=1 코믹=2 SF=3 로맨틱=4): ", stdout);
	//gets(genre);
	scanf("%d", &genre);
	while (getchar()!='\n');

	if (!AddDVDInfo(ISBN, title, &genre))
	{
		puts("정상적 저장 실패!");
		system("pause");
		return;
	};
	puts("DVD 등록 완료");
	system("pause");


}

/* 함    수: void SearchCusInfo(void)
* 기    능: ID를 통한 회원 정보 검색
* 반    환: void
*
*/
void SearchDVDInfo(void)
{
	dvdInfo* pFindingDVD;
	char findingisbn[10];
	fputs("찾는 isbn 입력: ", stdout);
	gets(findingisbn);

	pFindingDVD = GetDVDPtrByID(findingisbn);
	if (pFindingDVD == NULL)
	{
		puts("해당ID 부존");
		system("pause");
		return;
	}

	ShowDVDInfo(pFindingDVD);
}

/* end of file */