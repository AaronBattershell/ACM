//**********************************************************************************************************
// Aaron Battershell
// 2/22/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=516
//**********************************************************************************************************

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int sum;
    string number;

    while (true) {
        cin >> number;
        if(number == "0")
            break;

        sum = 0;
        for(int i = 0; i < number.length(); i++)
            sum += (number[i] - '0') * (pow(2, number.length()-i) - 1);

        cout << sum << endl;
    }

    return 0;
}
