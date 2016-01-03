/* Name: cusInfoCAccess.c  ver 1.0
 * Content: �� ���� ���� �� ���� �Լ����� ����
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER  100
#define CUS_BACKUP "cusinfo.dat"

static cusInfo * cusList[MAX_CUSTOMER];
static int numOfCustomer=0;

/* ��    ��: int AddCusInfo (char * ID, char * name, char * num)
 * ��    ��: cusInfo �Ҵ� �� ����. 
 * ��    ȯ: ���� �� '��ϵ� ������ ��', ���� �� 0�� ��ȯ.
			����� ��ȯ������ �����˻� ��.
 *
 */
int AddCusInfo(char * ID, char * name, char * num)
{
	if (numOfCustomer>=100)
	{
		puts("��ϰ����� ����ڼ� �ʰ�");
		return 0;
	}

	cusList[numOfCustomer] = (cusInfo*)malloc(sizeof(cusInfo));
	strcpy(cusList[numOfCustomer]->ID, ID);
	strcpy(cusList[numOfCustomer]->name, name);
	strcpy(cusList[numOfCustomer]->phoneNum, num);
	numOfCustomer++;

	saveCUSINFO();
	return numOfCustomer;
}


/* ��    ��: cusInfo * GetCusPtrByID(char * ID)
 * ��    ��: �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ 
 * ��    ȯ: ��� �ȵ� ID�� ��� NULL ������ ��ȯ.
 *
 */
cusInfo * GetCusPtrByID(char * ID)
{
	int i = 0;
	for (i = 0; i < numOfCustomer; i++)
	{
		if (strcmp(ID, cusList[i]->ID) == 0)
		{
			return cusList[i];
		}
	}
	return NULL;
}


/* ��    ��: int IsRegistID(char * ID)
 * ��    ��: ���� �� ID���� Ȯ��. 
 * ��    ȯ: ���� �Ǿ����� 1, �ƴϸ� 0 ��ȯ.
 *
 */
int IsRegistID(char * ID)
{
	int i = 0;

	if (GetCusPtrByID(ID) == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	//for ( i = 0; i < numOfCustomer; i++)
	//{
	//	if (!strcmp(ID,cusList[i]->ID))
	//	{
	//		printf("%s and %s", ID, cusList[i]->ID);
	//		return 1;
	//	}
	//}
	//return 0;
}


void loadCUSINFO(void) //����ü ������ �迭
{
	int i;

	FILE* SaveData = fopen(CUS_BACKUP, "rb");
	fread(SaveData, sizeof(int), 1, &numOfCustomer);

	for ( i = 0; i < numOfCustomer; i++)
	{
		fread(cusList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}

void saveCUSINFO(void) //�������͹迭
{
	int i;

	FILE* SaveData = fopen(CUS_BACKUP, "wb");
	if (SaveData == NULL)
		return;

	fwrite(SaveData, sizeof(int), 1, &numOfCustomer);

	for ( i = 0; i < numOfCustomer; i++)
	{
		fwrite(cusList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}


/* end of file */