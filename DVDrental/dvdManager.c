/* Name: cusManager.c  ver 1.0
* Content: dvd ���� ���� ó�� �Լ�.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

//�̰͵� �ʿ�..�Ƶ���ȿ��,�̸������ö�.
#include "cusInfoAccess.h"

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
	//gets(genre);
	scanf("%d", &genre);
	while (getchar()!='\n');

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

void HistoryOfRent(void)
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

	ShowRentHistory(pFindingDVD);
	
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
	pdvd->rentList[pdvd->numOfRentCus].rentDay = rentingday; //��¥����
	strcpy(pdvd->rentList[pdvd->numOfRentCus].cusID, rentingID); //���̵𺹻�

	//numof rentcus ++
	pdvd->numOfRentCus++;
	

	puts("�뿩 �Ϸ�...");
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

	//�ݳ�����
	//rentstate change
	pdvd->rentState = RETURNED;

	puts("�ݳ� �Ϸ�...");
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