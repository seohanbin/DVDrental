/* Name: rentInfoAccess.h  ver 1.0
* Content: DVD �뿩 ���� ����/���� �Լ����� ����.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#ifndef __RENTACCESS_H__
#define __RENTACCESS_H__

void AddRentList(char * ISBN, char * cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBN);
void PrintOutCusAllRentInfo(char * ID, unsigned int start, unsigned int end);

#endif
/* end of file */