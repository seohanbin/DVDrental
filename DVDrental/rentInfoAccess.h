/* Name: rentInfoAccess.h  ver 1.0
* Content: DVD 대여 정보 저장/참조 함수들의 선언.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

void AddRentList(char * ISBN, char * cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBN);
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);

void loadRENTINFO(void);
void saveRENTINFO(void);

#endif
/* end of file */