//**********************************************************************************************************
// Aaron Battershell
// 3/11/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2947
//**********************************************************************************************************
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int barLen, splits;

    while(true) {
        cin >> barLen;
        if(barLen == 0)
            break;

        for(int i = 0; true; i++) {
            if(barLen >= pow(2, i))
                continue;
            else {
                splits = i-1;
                break;
            }
        }

        cout << splits << endl;
    }

    return 0;
}
