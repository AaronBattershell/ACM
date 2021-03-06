//**********************************************************************************************************
// Aaron Battershell
// 2/28/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=66
//**********************************************************************************************************

#include <iostream>
using namespace std;

bool stillAlive(int [], int);

int main()
{
    int peopleCount;
    int stepCount;
    int index;
    int startIndex;
    int buryIndex;
    int list[100];

    while(true) {
        cin >> peopleCount;
        cin >> stepCount;
        startIndex = -1;
        if(peopleCount == 0 && stepCount == 0)
            break;
        if(peopleCount == 0) {
            cout << 1 << endl;
            continue;
        }

        while(true) {
            for(int i = 0; i < peopleCount; i++)
                list[i] = i;
            startIndex++;
            index = startIndex -1;

            for(int i = 0; i < peopleCount-1; i++) {
                //Find person to be killed
                int n = 0;
                while(n < stepCount) {
                    index++;
                    if(index > peopleCount-1)
                        index = 0;
                    if(list[index] == -1)
                        continue;
                    else
                        n++;
                }
                //find person to bury/take their place
                n = 0;
                buryIndex = index;
                while(n < stepCount) {
                    buryIndex++;
                    if(buryIndex > peopleCount-1)
                        buryIndex = 0;
                    if(list[buryIndex] == -1 || list[buryIndex] == list[index])
                        continue;
                    else
                        n++;
                }

                //Kill, and swap places
                if(list[index] != 0) {
                    list[index] = list[buryIndex];
                    list[buryIndex] = -1;
                }
                else {
                    list[index] = -1;
                    break;
                }
            }

            if(stillAlive(list, peopleCount))
                break;
        }

        cout << startIndex+1 << endl;
    }

    return 0;
}

bool stillAlive(int list[], int size) {
    for(int i = 0; i < size; i++)
        if(list[i] == 0)
            return true;
    return false;
}
