/* Name: screenOut.c  ver 1.0
 * Content: �ܼ� ����� ���� �Լ� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusInfo.h"

/* ���α׷� ����� ���� �޴� */
void ShowMenu(void)
{
    system("cls");   //stdlib.h
    
    printf("���������� ��  �� �������������� \n");
    printf(" 1. �ű԰��� \n");
    printf(" 2. ���˻� \n");
    printf(" 3. ���� \n");
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


/* end of file */