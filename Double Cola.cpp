//**********************************************************************************************************
// Aaron Battershell
// 4/14/13
// http://codeforces.com/problemset/problem/82/A
//**********************************************************************************************************
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int drinkIndex, sectionIndex, peoplePerSection, sizeList[30] = {0};
    string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    for(int i = 1; i < 30; i++)
        sizeList[i] = 5 * pow(2, i-1) + sizeList[i-1];

    while(cin >> drinkIndex) {
        for(int i = 0; true; i++) {
            if(drinkIndex <= sizeList[i]) {
                sectionIndex = i-1;
                peoplePerSection = pow(2,i-1);
                break;
            }
        }

        cout << names[((drinkIndex - sizeList[sectionIndex]) -1)/peoplePerSection] << endl;
    }

    return 0;
}
