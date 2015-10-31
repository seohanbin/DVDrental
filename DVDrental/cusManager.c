/* Name: cusManager.c  ver 1.0
 * Content: 고객 관련 업무 처리 함수.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

/* 함    수: void RegistCustomer(void)
 * 기    능: 신규 회원 가입. 
 * 반    환: void
 *
 */
void RegistCustomer(void)
{
	char id[10];
	char name[100];
	char phone[100];


	fputs("ID 입력: ", stdout);
	gets(id);
	if (IsRegistID(id))
	{
		puts("이미 존재하는 아이디..재시도 필요");
		system("pause");
		return;
	}

	fputs("이름 입력: ", stdout);
	gets(name);

	fputs("전번 입력: ", stdout);
	gets(phone);
	
	if (!AddCusInfo(id, name, phone))
	{
		puts("정상적 저장 실패!");
		system("pause");
		return;
	};
	puts("가입 완료");
	system("pause");


}

/* 함    수: void SearchCusInfo(void)
 * 기    능: ID를 통한 회원 정보 검색
 * 반    환: void
 * 
 */
void SearchCusInfo(void)
{
	cusInfo* pFindingCus;
	char findingID[10];
	fputs("찾는 ID 입력: ", stdout);
	gets(findingID);

	pFindingCus = GetCusPtrByID(findingID);
	if (pFindingCus==NULL)
	{
		puts("해당ID 부존");
		system("pause");
		return;
	}

	ShowCustomerInfo(pFindingCus);
}

/* end of file */