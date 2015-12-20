/* Name: dvdInfo.h  ver 1.0
 * Content: 영화 DVD 관리 구조체
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h" //커스터머정보도 필요

#define ISBN_LEN   30
#define TITLE_LEN  30

#define RENT_LEN  100

enum {ACTION=1, COMIC, SF, ROMANTIC}; // 장르 정보
enum { RENTED, RETURNED };    // 대여 상태를 나타내는 상수!

typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];    // 대여 고객 ID
	unsigned int rentDay;    // 대여일
} dvdRentInfo;

typedef struct __dvdInfo 
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;      // 장르

	int rentState;
	int numOfRentCus;
	dvdRentInfo rentList[RENT_LEN]; //포인터가아니라 구조체 배열 이용..=>말록같은것필요 x
}dvdInfo;

#endif
/* end of file */