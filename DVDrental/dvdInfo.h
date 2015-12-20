/* Name: dvdInfo.h  ver 1.0
 * Content: ��ȭ DVD ���� ����ü
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h" //Ŀ���͸������� �ʿ�

#define ISBN_LEN   30
#define TITLE_LEN  30

#define RENT_LEN  100

enum {ACTION=1, COMIC, SF, ROMANTIC}; // �帣 ����
enum { RENTED, RETURNED };    // �뿩 ���¸� ��Ÿ���� ���!

typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];    // �뿩 �� ID
	unsigned int rentDay;    // �뿩��
} dvdRentInfo;

typedef struct __dvdInfo 
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;      // �帣

	int rentState;
	int numOfRentCus;
	dvdRentInfo rentList[RENT_LEN]; //�����Ͱ��ƴ϶� ����ü �迭 �̿�..=>���ϰ������ʿ� x
}dvdInfo;

#endif
/* end of file */