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
#include "rentInfo.h"
//�����丮ȣ��þ��̵� ���� Ŀ�������� �׼����ʿ�..
#include "cusInfoAccess.h"


/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
    system("cls");   //stdlib.h
    
    printf("���������� ��  �� �������������� \n");
    printf(" 1. �ű԰��� \n");
    printf(" 2. ���˻� \n");
	printf("�������������������������������� \n");

	printf(" 3. DVD��� \n");
	printf(" 4. DVDã�� \n");
	printf("�������������������������������� \n");

	printf(" 5. DVD �뿩 \n");
	printf(" 6. DVD �ݳ� \n");
	printf("�������������������������������� \n");

    printf(" 7. DVD �뿩�� ��ü��� \n");
	printf(" 8. ���� \n");
    printf("�������������������������������� \n");
    printf("���á� ");
}


/* �� ������ �⺻ ���� ��� */
void ShowCustomerInfo(cusInfo * pCus)
{
    
    printf("���������������������������������� \n");
    printf("�� �� ID: %s \n", pCus->ID);
    printf("�� �� �̸�: %s \n", pCus->name);
    printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
    printf("���������������������������������� \n\n");
    
	system("pause");
	//system("cls");   //stdlib.h
	//�����丮�����ٶ� ������ �ȵ�..
}

void ShowCustomerInfocontinue(cusInfo * pCus)
{

	printf("���������������������������������� \n");
	printf("�� �� ID: %s \n", pCus->ID);
	printf("�� �� �̸�: %s \n", pCus->name);
	printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
	printf("���������������������������������� \n\n");

	//system("pause");
	//system("cls");   //stdlib.h
	//�����丮�����ٶ� ������ �ȵ�..
}

/* DVD �⺻ ���� ��� */
void ShowDVDInfo(dvdInfo * pCus)
{

	printf("���������������������������������� \n");
	printf("�� �� ISBN: %s \n", pCus->ISBN);
	printf("�� �� title: %s \n", pCus->title);
	printf("�� �� genre: "); ShowGenre(pCus->genre); puts("");
	printf("���������������������������������� \n\n");

	system("pause");
	system("cls");   //stdlib.h

}

void ShowDVDrentInfo(dvdRentInfo pRinfo)
{

	printf("���������������������������������� \n");
	printf("�� �� ISBN: %s \n", pRinfo.ISBN);
	printf("�� �� �뿩��: %d\n", pRinfo.rentDay);
	printf("���������������������������������� \n\n");

}

//void ShowRentHistory(dvdInfo * pCus)
//{//����ٰ� �����丮 ����
//
//	int i;
//	for ( i = 0; i < pCus->numOfRentCus ; i++)
//	{
//		printf("�뿩��: %d \n", pCus->rentList[i].rentDay);
//		ShowCustomerInfocontinue(GetCusPtrByID(pCus->rentList[i].cusID));
//		printf("�������������������������������� \n");
//	}
//
//
//}


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