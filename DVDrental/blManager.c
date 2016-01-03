//dvdM
#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

#include "rentInfoAccess.h"

//�̰͵� �ʿ�..�Ƶ���ȿ��,�̸������ö�.
//#include "cusInfoAccess.h"

//#include "cusInfo.h" //ID_LEN �����ö� �ʿ�..

//cusM
//#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
//#include "screenOut.h"

//FUNC_ dvd
/* ��    ��: void RegistCustomer(void)
* ��    ��: �ű� ȸ�� ����.
* ��    ȯ: void
*
*/
void RegistDVD(void)
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;      // �帣


	fputs("Isbn �Է�: ", stdout);
	gets(ISBN);
	if (IsRegistDVD(ISBN))
	{
		puts("�̹� �����ϴ� ISBN..��õ� �ʿ�");
		system("pause");
		return;
	}

	fputs("Ÿ��Ʋ �Է�: ", stdout);
	gets(title);


	fputs("�帣 �Է�(�׼�=1 �ڹ�=2 SF=3 �θ�ƽ=4): ", stdout);
	scanf("%d", &genre);
	while (getchar() != '\n');

	if (!AddDVDInfo(ISBN, title, &genre))
	{
		puts("������ ���� ����!");
		system("pause");
		return;
	};
	puts("DVD ��� �Ϸ�");
	system("pause");


}


/* ��    ��: void SearchCusInfo(void)
* ��    ��: ID�� ���� ȸ�� ���� �˻�
* ��    ȯ: void
*
*/
void SearchDVDInfo(void)
{
	dvdInfo* pFindingDVD;
	char findingisbn[ISBN_LEN];
	fputs("ã�� isbn �Է�: ", stdout);
	gets(findingisbn);

	pFindingDVD = GetDVDPtrByID(findingisbn);
	if (pFindingDVD == NULL)
	{
		puts("�ش�isbn ����");
		system("pause");
		return;
	}

	ShowDVDInfo(pFindingDVD);
}

//void HistoryOfRentByISBN(void)

void HistoryOfRentByISBN(void)
{ //�̰��� ���� ��ũ���ƿ� ȣ���ҵ�...

	int i;
	char isbn_finding[ISBN_LEN];
	dvdInfo* pFindingDVD;


	fputs("ã�� ���� ISBN: ", stdout);
	gets(isbn_finding);

	pFindingDVD = GetDVDPtrByID(isbn_finding);
	if (pFindingDVD == NULL)
	{
		puts("�ش�Isbn ����");
		system("pause");
		return;
	}
	else
	{
		puts("��ȿ�� ISBN..����");
	}
	//ShowRentHistory(pFindingDVD);
	PrintOutRentAllCusInfo(isbn_finding);
	system("pause");
}

void HistoryOfRentByCus(void)
{
	char id_finding[ID_LEN];
	int day_StartFinding, day_EndFinding;

	fputs("ã�� ID: ", stdout);
	gets(id_finding);

	//id validation
	if (GetCusPtrByID(id_finding)) //���⼭ pRentingCus�� Ŀ���͸������͸� �Ҵ��Ѵ�(���� ���� �ʴ´�)
	{
		puts("��ȿ�� �Ƶ�.. ����");
	}
	else
	{//0�̸�.. NULL�̸�
		puts("invalid ID exiting..");
		system("pause");
		return;
	}


	fputs("�Ⱓ(���� �ΰ� space�� ����, ������ ������): ", stdout);
	scanf("%d %d", &day_StartFinding, &day_EndFinding);
	while (getchar() != '\n');

	if (day_StartFinding>day_EndFinding)
	{
		puts("�������� �����Ϻ��� ����..(����)");
		return;
	}
	PrintOutCusAllRentInfo(id_finding, day_StartFinding, day_EndFinding);
	puts("��ȸ�Ϸ�..");
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


	fputs("�뿩�� ���� ISBN: ", stdout);
	gets(ISBN);

	if (pdvd = GetDVDPtrByID(ISBN)) //���⼭ pdvd �� �������� ���� �Ҵ��Ѵ�-> �Ⱦ�
	{
		puts("��ȿ�� isbn..");
	}
	else
	{
		puts("��ȿ���� ���� isbn");
		system("pause");
		return;
	}


	if (pdvd->rentState == RENTED)
	{
		puts("�뿩���̶� �뿩�Ұ���");
		system("pause");
		return;
	}
	else
	{
		puts("�뿩���ɻ���.. �뿩����");
	}


	fputs("�뿩�� id�Է�: ", stdout);
	gets(rentingID);
	//id validation
	if (pRentingCus = GetCusPtrByID(rentingID)) //���⼭ pRentingCus�� Ŀ���͸������͸� �Ҵ��Ѵ�(���� ���� �ʴ´�)
	{
		puts("��ȿ�� �Ƶ�.. ����");
	}
	else
	{//0�̸�.. NULL�̸�
		puts("invalid ID exiting..");
		system("pause");
		return;
	}


	fputs("�뿩��¥ �Է�(����): ", stdout);
	scanf("%d", &rentingday);
	while (getchar() != '\n');


	//�뿩����
	//rentstate change
	pdvd->rentState = RENTED;

	//rentlifo ADDING..(���̵� ����, ��¥ ����)
	//pdvd->rentList[pdvd->numOfRentCus].rentDay = rentingday; //��¥����
	//strcpy(pdvd->rentList[pdvd->numOfRentCus].cusID, rentingID); //���̵𺹻�

	AddRentList(ISBN, rentingID, rentingday);

	//numof rentcus ++
	//pdvd->numOfRentCus++;


	puts("�뿩 �Ϸ�...");
	saveDVDINFO();
	system("pause");


}

void ReturnDVD()
{

	char ISBN[ISBN_LEN];
	dvdInfo* pdvd;



	fputs("�ݳ��� ���� ISBN: ", stdout);
	gets(ISBN);

	if (pdvd = GetDVDPtrByID(ISBN)) //���⼭ pdvd �� �������� ���� �Ҵ��Ѵ�
	{
		puts("��ȿ�� isbn..");
	}
	else
	{
		puts("��ȿ���� ���� isbn");
		system("pause");
		return;
	}

	if (pdvd->rentState == RENTED)
	{
		puts("�뿩���̶� �ݳ�����");
	}
	else
	{
		puts("�̹̹ݳ���.... �ݳ��Ұ���");
		system("pause");
		return;
	}


	//�ݳ�����
	//rentstate change
	pdvd->rentState = RETURNED;

	puts("�ݳ� �Ϸ�...");
	saveDVDINFO();
	system("pause");

}
/* end of file */



void Registdvdseed(void)
{
	int a = 1;
	int b = 2;
	int c = 3;
	puts("�õ� ���� ����..");
	AddDVDInfo("4567", "rtyu", &a);
	AddDVDInfo("5678", "tyui", &b);
	AddDVDInfo("6789", "yuio", &c);

	puts("�õ� ���� �Ϸ�...");
	system("pause");
}



//FUNC_CUS
/* ��    ��: void RegistCustomer(void)
* ��    ��: �ű� ȸ�� ����.
* ��    ȯ: void
*
*/
void RegistCustomer(void)
{
	char id[10];
	char name[100];
	char phone[100];


	fputs("ID �Է�: ", stdout);
	gets(id);
	if (IsRegistID(id))
	{
		puts("�̹� �����ϴ� ���̵�..��õ� �ʿ�");
		system("pause");
		return;
	}

	fputs("�̸� �Է�: ", stdout);
	gets(name);

	fputs("���� �Է�: ", stdout);
	gets(phone);

	if (!AddCusInfo(id, name, phone))
	{
		puts("������ ���� ����!");
		system("pause");
		return;
	};
	puts("���� �Ϸ�");
	system("pause");


}

/* ��    ��: void SearchCusInfo(void)
* ��    ��: ID�� ���� ȸ�� ���� �˻�
* ��    ȯ: void
*
*/
void SearchCusInfo(void)
{
	cusInfo* pFindingCus;
	char findingID[10];
	fputs("ã�� ID �Է�: ", stdout);
	gets(findingID);

	pFindingCus = GetCusPtrByID(findingID);
	if (pFindingCus == NULL)
	{
		puts("�ش�ID ����");
		system("pause");
		return;
	}

	ShowCustomerInfo(pFindingCus);
}

void Registcusseed(void)
{
	puts("�õ� Ŀ���� ����..");
	AddCusInfo("1234", "qwer", "asdf");
	AddCusInfo("2345", "wert", "sdfg");
	AddCusInfo("3456", "erty", "dfgh");
	puts("�õ� Ŀ���� �Ϸ�..");
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
