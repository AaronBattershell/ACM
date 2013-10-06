//**********************************************************************************************************
// Aaron Battershell
// 3/1/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1281
//**********************************************************************************************************

#include <iostream>
using namespace std;

int main()
{
    string phrase1;
    string phrase2;
    bool good;

    while(cin >> phrase1) {
        cin >> phrase2;
        good = false;

        int index = 0;
        for(int i = 0; i < phrase2.length(); ++i) {
            if(phrase2[i] == phrase1[index])
                index++;

            if(index == phrase1.length()) {
                good = true;
                break;
            }
        }
        cout << (good ? "Yes" : "No") << endl;
    }
    return 0;
}
