//**********************************************************************************************************
// Aaron Battershell
// 4/04/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=379
//**********************************************************************************************************
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double x1, x2, x3, y1, y2, y3;
    double a, b, c;
    double radius, pi = 3.141592653589793;

    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
        c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

        radius = (a * b * c) / sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
        cout << fixed << setprecision(2) << (2*pi*radius) << endl;
    }

    return 0;
}
