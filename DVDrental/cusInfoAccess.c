/* Name: cusInfoCAccess.c  ver 1.0
 * Content: �� ���� ���� �� ���� �Լ����� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER  100

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/* ��    ��: int AddCusInfo (char * ID, char * name, char * num)
 * ��    ��: cusInfo �Ҵ� �� ����. 
 * ��    ȯ: ���� �� '��ϵ� ������ ��', ���� �� 0�� ��ȯ.
 *
 */
int AddCusInfo(char * ID, char * name, char * num)
{
}


/* ��    ��: cusInfo * GetCusPtrByID(char * ID)
 * ��    ��: �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ 
 * ��    ȯ: ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
 *
 */
cusInfo * GetCusPtrByID(char * ID)
{
}


/* ��    ��: int IsRegistID(char * ID)
 * ��    ��: ���� �� ID���� Ȯ��. 
 * ��    ȯ: ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ.
 *
 */
int IsRegistID(char * ID)
{
}

/* end of file */