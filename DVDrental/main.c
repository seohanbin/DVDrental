/* Name: main.c  ver 1.0
 * Content: DVD 대여 관리 프로그램 main 
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "screenOut.h"

#include "cusManager.h"
#include "dvdManager.h"

enum{CUS_REGIST=1, CUS_SEARCH, 
	DVD_REGIST, DVD_SEARCH, 
	DVD_RENT, DVD_RETURN, 
	DVD_RENTHISTORY, QUIT,
	SEEDDATA};//씨드는 9번!

int main(void)
{
    int inputMenu = 0;
    
    while(1)
    {
        ShowMenu();
        scanf("%d", &inputMenu);
		while (getchar() != '\n');

        switch(inputMenu)
        {
        case CUS_REGIST:
            RegistCustomer();
            break;
        
        case CUS_SEARCH:
            SearchCusInfo();
            break;

		case DVD_REGIST:
			RegistDVD();
			break;

		case DVD_SEARCH:
			SearchDVDInfo();
			break;

		case DVD_RENT:
			RentDVD();
			break;

		case DVD_RETURN:
			ReturnDVD();
			break;

		case DVD_RENTHISTORY:
			HistoryOfRent();
			break;

		case SEEDDATA:
			puts("시드데이터 시작..");
			Registdvdseed();
			Registcusseed();
			break;
        }
        
        if(inputMenu==QUIT)
        {
            puts("normal exit");
            break;
        }
    }    

    return 0;
}

/* end of file */