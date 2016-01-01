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
	DVD_RENTHISTORY, CUS_RENTHISTORY,	
	QUIT,
	SEEDDATA};//씨드는 10번!

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
        case CUS_REGIST: //1
            RegistCustomer();
            break;
        
        case CUS_SEARCH: //2
            SearchCusInfo();
            break;

		case DVD_REGIST: //3
			RegistDVD();
			break;

		case DVD_SEARCH: //4
			SearchDVDInfo();
			break;

		case DVD_RENT: //5
			RentDVD();
			break;

		case DVD_RETURN: //6
			ReturnDVD();
			break;

		case DVD_RENTHISTORY: //7
			HistoryOfRentByISBN();
			break;

		case CUS_RENTHISTORY: //8
			HistoryOfRentByCus();
			break;

		case SEEDDATA: //10
			puts("시드데이터 시작..");
			Registdvdseed();
			Registcusseed();
			break;
        }
        
        if(inputMenu==QUIT) //9
        {
            puts("normal exit");
            break;
        }
    }    

    return 0;
}

/* end of file */