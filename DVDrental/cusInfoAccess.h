/* Name: cusInfoAccess.h  ver 1.0
 * Content: 고객 정보 저장 및 참조 함수들의 선언
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __CUSCONTROL_H__
#define __CUSCONTROL_H__

#include "cusInfo.h"

int AddCusInfo(char * ID, char * name, char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsRegistID(char * ID);

void loadCUSINFO(void);
void saveCUSINFO(void);

#endif

/* end of file */