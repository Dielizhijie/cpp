#include "System.h"
using namespace std;

/**
 * 小端存储返回0，打断存储返回1
 * @return bool类型
 */
bool System::IsBig_Ending() {
    unsigned short test = 0x1234;
    if(*((unsigned char*) & test) == 0x12){
        return 1;
    }else{
        return 0;
    }
}


