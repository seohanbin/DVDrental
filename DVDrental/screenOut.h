/* Name: screenOut.h  ver 1.0
 * Content: 콘솔 출력을 위한 함수 선언
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowCustomerInfocontinue(cusInfo * pCus);

void ShowDVDInfo(dvdInfo * pCus);
void ShowGenre(int gen);
void ShowRentHistory(dvdInfo * pCus);

#endif

/* end of file */