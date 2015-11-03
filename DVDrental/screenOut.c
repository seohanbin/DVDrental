/* Name: screenOut.c  ver 1.0
 * Content: �ܼ� ����� ���� �Լ� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "screenOut.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
    system("cls");   //stdlib.h
    
    printf("���������� ��  �� �������������� \n");
    printf(" 1. �ű԰��� \n");
    printf(" 2. ���˻� \n");
	printf(" 3. DVD��� \n");
	printf(" 4. DVDã�� \n");
    printf(" 5. ���� \n");
    printf("�������������������������������� \n");
    printf("���á� ");
}


/* �� ������ �⺻ ���� ��� */
void ShowCustomerInfo(cusInfo * pCus)
{
    system("cls");   //stdlib.h
    
    printf("���������������������������������� \n");
    printf("�� �� ID: %s \n", pCus->ID);
    printf("�� �� �̸�: %s \n", pCus->name);
    printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
    printf("���������������������������������� \n\n");
    
	system("pause");
}

/* DVD �⺻ ���� ��� */
void ShowDVDInfo(dvdInfo * pCus)
{
	system("cls");   //stdlib.h

	printf("���������������������������������� \n");
	printf("�� �� ISBN: %s \n", pCus->ISBN);
	printf("�� �� title: %s \n", pCus->title);
	printf("�� �� genre: "); ShowGenre(pCus->genre); puts("");
	printf("���������������������������������� \n\n");

	system("pause");
}

//2���� ��� ��ȯ����. ���ڿ����void, ���ڿ���ȯchar*
void ShowGenre(int gen)
{
	switch (gen)
	{
	case ACTION:
		fputs("�׼�", stdout);
		break;
	case COMIC:
		fputs("�ڹ�", stdout);
		break;
	case SF:
		fputs("����", stdout);
		break;
	case ROMANTIC:
		fputs("�θ�ƽ", stdout);
		break;
	}
}

/* end of file */