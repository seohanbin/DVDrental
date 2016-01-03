#ifndef __DVDINFOACCESS_H__
#define __DVDINFOACCESS_H__

#include "dvdInfo.h"


int IsRegistDVD(char * ISBN);
dvdInfo * GetDVDPtrByID(char * ISBN);
int AddDVDInfo(char * isbn, char * title, int * genre);

void loadDVDINFO(void);
void saveDVDINFO(void);

#endif