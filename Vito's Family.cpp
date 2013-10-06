//**********************************************************************************************************
// Aaron Battershell
// 3/3/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=982
//**********************************************************************************************************

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int temp;
    int cases;
    int addressCount;
    int distance;
    vector<int>address;

    cin >> cases;
    for(int i = 0; i < cases; i++) {
        address.clear();
        distance = 0;

        cin >> addressCount;
        for(int n = 0; n < addressCount; n++) {
            cin >> temp;
            address.push_back(temp);
        }

        sort(address.begin(), address.end());
        for(int n = 0; n < addressCount; n++)
            distance += abs(address[n] - address[(address.size()-1) /2]);

        cout << distance << endl;
    }

    return 0;
}
