//**********************************************************************************************************
// Aaron Battershell
// 3/16/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2489
//**********************************************************************************************************
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int x1, y1;
    int x2, y2;

    while(true) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(!x1 && !x2 && ! y1 && !y2)
            break;

        if(x1 == x2 && y1 == y2)
            cout << 0;
        else if(x1 == x2 || y1 == y2)
            cout << 1;
        else if(abs(x1 - x2) == abs(y1 - y2))
            cout << 1;
        else
            cout << 2;

        cout << endl;
    }

    return 0;
}
