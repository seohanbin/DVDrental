/* Name: cusManager.c  ver 1.0
 * Content: �� ���� ���� ó�� �Լ�.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

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
	if (pFindingCus==NULL)
	{
		puts("�ش�ID ����");
		system("pause");
		return;
	}

	ShowCustomerInfo(pFindingCus);
}

/* end of file */