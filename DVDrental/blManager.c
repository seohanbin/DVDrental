//dvdM
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

#include "rentInfoAccess.h"

//이것도 필요..아디유효성,이름가져올때.
//#include "cusInfoAccess.h"

//#include "cusInfo.h" //ID_LEN 가져올때 필요..

//cusM
//#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
//#include "screenOut.h"

//FUNC_ dvd
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
	scanf("%d", &genre);
	while (getchar() != '\n');

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
	char findingisbn[ISBN_LEN];
	fputs("찾는 isbn 입력: ", stdout);
	gets(findingisbn);

	pFindingDVD = GetDVDPtrByID(findingisbn);
	if (pFindingDVD == NULL)
	{
		puts("해당isbn 부존");
		system("pause");
		return;
	}

	ShowDVDInfo(pFindingDVD);
}

//void HistoryOfRentByISBN(void)

void HistoryOfRentByISBN(void)
{ //이것을 통해 스크린아웃 호출할듯...

	int i;
	char isbn_finding[ISBN_LEN];
	dvdInfo* pFindingDVD;


	fputs("찾는 디비디 ISBN: ", stdout);
	gets(isbn_finding);

	pFindingDVD = GetDVDPtrByID(isbn_finding);
	if (pFindingDVD == NULL)
	{
		puts("해당Isbn 부존");
		system("pause");
		return;
	}
	else
	{
		puts("유효한 ISBN..진행");
	}
	//ShowRentHistory(pFindingDVD);
	PrintOutRentAllCusInfo(isbn_finding);
	system("pause");
}

void HistoryOfRentByCus(void)
{
	char id_finding[ID_LEN];
	int day_StartFinding, day_EndFinding;

	fputs("찾는 ID: ", stdout);
	gets(id_finding);

	//id validation
	if (GetCusPtrByID(id_finding)) //여기서 pRentingCus에 커스터머포인터를 할당한다(실은 쓰지 않는다)
	{
		puts("유효한 아디.. 진행");
	}
	else
	{//0이면.. NULL이면
		puts("invalid ID exiting..");
		system("pause");
		return;
	}


	fputs("기간(정수 두개 space로 구분, 시작일 종료일): ", stdout);
	scanf("%d %d", &day_StartFinding, &day_EndFinding);
	while (getchar() != '\n');

	if (day_StartFinding>day_EndFinding)
	{
		puts("종료일이 시작일보다 빠름..(오류)");
		return;
	}
	PrintOutCusAllRentInfo(id_finding, day_StartFinding, day_EndFinding);
	puts("조회완료..");
	system("pause");

}

void RentDVD()
{
	char ISBN[ISBN_LEN];
	dvdInfo* pdvd;
	char rentingID[10];
	char rentername[30];
	int rentingday;
	cusInfo* pRentingCus;


	fputs("대여할 디비디 ISBN: ", stdout);
	gets(ISBN);

	if (pdvd = GetDVDPtrByID(ISBN)) //여기서 pdvd 에 빌리려는 디비디를 할당한다-> 안씀
	{
		puts("유효한 isbn..");
	}
	else
	{
		puts("유효하지 않은 isbn");
		system("pause");
		return;
	}


	if (pdvd->rentState == RENTED)
	{
		puts("대여중이라 대여불가능");
		system("pause");
		return;
	}
	else
	{
		puts("대여가능상태.. 대여진행");
	}


	fputs("대여할 id입력: ", stdout);
	gets(rentingID);
	//id validation
	if (pRentingCus = GetCusPtrByID(rentingID)) //여기서 pRentingCus에 커스터머포인터를 할당한다(실은 쓰지 않는다)
	{
		puts("유효한 아디.. 진행");
	}
	else
	{//0이면.. NULL이면
		puts("invalid ID exiting..");
		system("pause");
		return;
	}


	fputs("대여날짜 입력(정수): ", stdout);
	scanf("%d", &rentingday);
	while (getchar() != '\n');


	//대여과정
	//rentstate change
	pdvd->rentState = RENTED;

	//rentlifo ADDING..(아이디만 복사, 날짜 대입)
	//pdvd->rentList[pdvd->numOfRentCus].rentDay = rentingday; //날짜대입
	//strcpy(pdvd->rentList[pdvd->numOfRentCus].cusID, rentingID); //아이디복사

	AddRentList(ISBN, rentingID, rentingday);

	//numof rentcus ++
	//pdvd->numOfRentCus++;


	puts("대여 완료...");
	saveDVDINFO();
	system("pause");


}

void ReturnDVD()
{

	char ISBN[ISBN_LEN];
	dvdInfo* pdvd;



	fputs("반납할 디비디 ISBN: ", stdout);
	gets(ISBN);

	if (pdvd = GetDVDPtrByID(ISBN)) //여기서 pdvd 에 빌리려는 디비디를 할당한다
	{
		puts("유효한 isbn..");
	}
	else
	{
		puts("유효하지 않은 isbn");
		system("pause");
		return;
	}

	if (pdvd->rentState == RENTED)
	{
		puts("대여중이라 반납가능");
	}
	else
	{
		puts("이미반납됨.... 반납불가능");
		system("pause");
		return;
	}


	//반납과정
	//rentstate change
	pdvd->rentState = RETURNED;

	puts("반납 완료...");
	saveDVDINFO();
	system("pause");

}
/* end of file */



void Registdvdseed(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	puts("시드 디비디 시작..");
	AddDVDInfo("4567", "rtyu", &a);
	AddDVDInfo("5678", "tyui", &b);
	AddDVDInfo("6789", "yuio", &c);

	puts("시드 디비비 완료...");
	system("pause");
}



//FUNC_CUS
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
	if (pFindingCus == NULL)
	{
		puts("해당ID 부존");
		system("pause");
		return;
	}

	ShowCustomerInfo(pFindingCus);
}

void Registcusseed(void)
{
	puts("시드 커스텀 시작..");
	AddCusInfo("1234", "qwer", "asdf");
	AddCusInfo("2345", "wert", "sdfg");
	AddCusInfo("3456", "erty", "dfgh");
	puts("시드 커스텀 완료..");
	system("pause");
}





void loadData(void)
{
	loadCUSINFO();
	loadDVDINFO();
	loadRENTINFO();
}

void saveData(void)
{
	saveCUSINFO();
	saveDVDINFO();
	saveRENTINFO();
}



/* end of file */
