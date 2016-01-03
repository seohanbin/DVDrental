/* Name: rentInfoAccess.c  ver 1.1
* Content: DVD �뿩 ���� ����/���� �Լ����� ����.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

//����..
#include "rentInfoAccess.h"

#define RENT_LEN  100
#define RENT_BACKUP "rentinfo.dat"

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

/* ��    ��: void AddRentList(char * ISBN, char * cusID, int rentDay)
* ��    ��: �뿩 ������ ����
* ��    ȯ: void
*
*/
void AddRentList(char * ISBN, char * cusID, int rentDay)
{
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	strcpy(rentList[numOfRentCus].cusID, cusID);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;

	saveRENTINFO();
}


/* ��    ��: void PrintOutRentAllCusInfo(char * ISBN)
* ��    ��: Ư�� ISBN�� DVD �뿩 �� ���� ���
* ��    ȯ: void
*
*/
void PrintOutRentAllCusInfo(char* ISBN)   // CusInfo, �� ���� ���
{
	int i;
	for ( i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ISBN, rentList[i].ISBN) == 0)//�׳ɾտ�!���ϼ��� ������
		{
			printf("�뿩��: %d\n", rentList[i].rentDay);
			ShowCustomerInfocontinue(GetCusPtrByID(rentList[i].cusID));
		}
	}
}

/* ��    ��: void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end)
* ��    ��: ���� �Ⱓ �ȿ� �̷��� Ư�� ���� DVD �뿩 ���� ���
* ��    ȯ: void
*
*/
void PrintOutCusAllRentInfo   //RentInfo, �뿩 ���� ���
(char * ID, unsigned int start, unsigned int end)
{
	int i;
	for ( i = 0; i < numOfRentCus; i++)
	{
		if (strcmp(ID, rentList[i].cusID) == 0)
		{
			if (start <= rentList[i].rentDay && rentList[i].rentDay<=end)
			{
				puts("#ShowDVDrentInfo(rentList[i]);");
				ShowDVDrentInfo(rentList[i]);
			}
		}
	}
}

void loadRENTINFO(void) //����ü / �迭
{
	int i;

	FILE* SaveData = fopen(RENT_BACKUP, "rb");
	if (SaveData == NULL)
		return;

	fread(SaveData, sizeof(int), 1, &numOfRentCus);

	for (i = 0; i < numOfRentCus; i++)
	{
		fread(&rentList[i], sizeof(cusInfo), 1, SaveData);
	}

	fclose(SaveData);
}

void saveRENTINFO(void) //����ü �迭
{

	FILE* SaveData = fopen(RENT_BACKUP, "wb");
	if (SaveData == NULL)
		return;

	fwrite(SaveData, sizeof(int), 1, &numOfRentCus);
	fwrite(rentList, sizeof(cusInfo), numOfRentCus, SaveData);

	fclose(SaveData);

}




/* end of file */