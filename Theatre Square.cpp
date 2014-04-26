//**********************************************************************************************************
// Aaron Battershell
// 4/5/13
// http://codeforces.com/problemset/problem/1/A
//**********************************************************************************************************
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    long double width, depth, flagStone;
    unsigned long long int widthCount, depthCount;
    
    while(cin >> width >> depth >> flagStone) {       
        widthCount = (fmod(width / flagStone, 1) <= .0000000000001 ? width / flagStone : (width / flagStone)  + 1);
        depthCount = (fmod(depth / flagStone, 1) <= .0000000000001 ? depth / flagStone : (depth / flagStone)  + 1);
        
        cout << fixed << setprecision(0) << (widthCount * depthCount) << endl;
    }
    
    return 0;
}
