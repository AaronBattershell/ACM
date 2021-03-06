//**********************************************************************************************************
// Aaron Battershell
// 2/22/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
//**********************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    int begin;
    int end;
    int hight;
    int currentHight = 0;
    bool space = false; //For propper white-space output

    int maxHight[10000];
    for(int i = 0; i < 10000; i++)
        maxHight[i] = 0;

    //Get input and find max hight per int
    while(cin >> begin) {
        cin >> hight;
        cin >> end;

        for(int i = begin; i < end; i++)
            if(maxHight[i] < hight)
                maxHight[i] = hight;
    }

    //Print when elevation changes
    for(int i = 1; i < 10000; i++) {
        if(maxHight[i] == 0) 
            if(currentHight != 0) {
                cout << " " << i << " " << 0;
                currentHight = 0;
            }
        if(maxHight[i] != currentHight) {
            currentHight = maxHight[i];
            if(space)
                cout << " ";
            cout << i << " " << currentHight;
            space = true;
        }
    }
    
    cout << endl;
    return 0;
}
