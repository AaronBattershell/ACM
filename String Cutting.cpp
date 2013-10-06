//**********************************************************************************************************
// Aaron Battershell
// 3/27/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3656
//**********************************************************************************************************
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void clearChar(bool []);
int getLastCut(int, vector<int>&);
int getNextCut(int, vector<int>&);

int main() {
    int cases, cutCount, cost;
    string phrase;
    bool charList1[26];
    bool charList2[26];
    vector<int>breakList;
    vector<int>currentBreaks;

    cin >> cases;
    for(int i = 0; i < cases; i++) {
        cost = 0;
        breakList.clear();
        currentBreaks.clear();
        cin >> cutCount;

        //Get all the cuts
        for(int n = 0; n < cutCount; n++) {
            int temp;
            cin >> temp;
            breakList.push_back(temp-1);
        }
        phrase = "0";
        cin >> phrase;
        phrase += "0";

        currentBreaks.push_back(-1);
        currentBreaks.push_back(phrase.length()-1);
        for(int n = 0; n < cutCount; n++) {
            clearChar(charList1);
            clearChar(charList2);
            currentBreaks.push_back(breakList[n]);
            sort(currentBreaks.begin(), currentBreaks.end());

            for(int j = getLastCut(breakList[n], currentBreaks); j <= breakList[n]; j++)
                charList1[phrase[j] - 'a'] = true;

            for(int j = breakList[n]+1; j <= getNextCut(breakList[n], currentBreaks); j++)
                charList2[phrase[j] - 'a'] = true;

            for(int j = 0; j < 26; j++)
                if(charList1[j] != charList2[j])
                    cost++;
        }

        cout << cost << endl;
    }

    return 0;
}

void clearChar(bool arr[]) {
    for(int i = 0; i < 26; i++)
        arr[i] = false;
}
int getLastCut(int find, vector<int> &list) {
    for(int i = 0; i < list.size(); i++)
        if(find == list[i])
            return list[i-1]+1;
    return 0;
}
int getNextCut(int find, vector<int> &list) {
    for(int i = 0; i < list.size(); i++)
        if(find == list[i])
            return list[i+1];
    return 0;
}
