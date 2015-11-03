/* Name: dvdInfo.h  ver 1.0
 * Content: 영화 DVD 관리 구조체
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN   30
#define TITLE_LEN  30

enum {ACTION=1, COMIC, SF, ROMANTIC}; // 장르 정보

typedef struct __dvdInfo 
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;      // 장르
}dvdInfo;

#endif
/* end of file */