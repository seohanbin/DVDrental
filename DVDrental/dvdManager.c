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
	char findingisbn[10];
	fputs("ã�� isbn �Է�: ", stdout);
	gets(findingisbn);

	pFindingDVD = GetDVDPtrByID(findingisbn);
	if (pFindingDVD == NULL)
	{
		puts("�ش�ID ����");
		system("pause");
		return;
	}

	ShowDVDInfo(pFindingDVD);
}

/* end of file */