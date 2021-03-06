//**********************************************************************************************************
// Aaron Battershell
// 2/28/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87
//**********************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    int sectors;
    int stepCount;
    int index;
    int list[100];

    while(true) {
        cin >> sectors;
        if(sectors == 0) 
            break;
        stepCount = 0;

        while(true) {
            for(int i = 0; i < sectors; i++)
                list[i] = i;
            index = 0;
            stepCount++;

            list[0] = -1;
            for(int i = 1; i < sectors-1; i++) {
                int n = 0;
                while(n < stepCount) {
                    index++;
                    if(index > sectors-1)
                        index = 0;
                    if(list[index] == -1)
                        continue;
                    else
                        n++;
                }
                if(list[index] != 12)
                    list[index] = -1;
                else {
                    list[index] = -1;
                    break;
                }
            }

            if(list[12] == 12)
                break;
        }

        cout << stepCount << endl;
    }

    return 0;
}
