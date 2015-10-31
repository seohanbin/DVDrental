/* Name: main.c  ver 1.0
 * Content: DVD �뿩 ���� ���α׷� main 
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum{CUS_REGIST=1, CUS_SEARCH, QUIT};

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