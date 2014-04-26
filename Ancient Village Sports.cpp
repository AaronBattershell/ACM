//**********************************************************************************************************
// Aaron Battershell
// 3/10/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1392
//**********************************************************************************************************
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int edges, cases = 0;
    double outRadius, inRadius, area, thayadaa;

    while(true) {
        cases++;
        cin >> edges >> area;
        if(edges < 3) break;

        thayadaa = 4*acos(0) / edges / 2;
        outRadius = sqrt((2 * area) / (edges * sin(4*acos(0) / edges)));
        inRadius = outRadius * cos(thayadaa);

        cout << "Case " << cases << ": " << fixed << showpoint << setprecision(5)
             << 2*acos(0)*pow(outRadius, 2) - area << " " << area - 2*acos(0)*pow(inRadius, 2) << endl;
    }

    return 0;
}
