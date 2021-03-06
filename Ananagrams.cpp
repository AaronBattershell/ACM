//**********************************************************************************************************
// Aaron Battershell
// 2/26/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=92
//**********************************************************************************************************

#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

void clearList(int []);
bool isMatch(int []);

int main()
{
    int letterList[26];
    bool add;
    string temp;
    vector<string>wordList;
    vector<string>uniqueList;

    while(true) {
        cin >> temp;
        if (temp == "#") break;
        else wordList.push_back(temp);
    }

    for(int i = 0; i < wordList.size(); i++) {
        add = true;
        for(int n = 0; n < wordList.size(); n++) {
            if(i == n) continue;
            clearList(letterList);

            temp = wordList[i];
            for(int j = 0; j < temp.length(); j++)
                letterList[tolower(temp[j]) - 'a']++;

            temp = wordList[n];
            for(int j = 0; j < temp.length(); j++) {
                letterList[tolower(temp[j]) - 'a']--;
                if(letterList[tolower(temp[j]) - 'a'] < 0)
                    break;
            }

            if(isMatch(letterList)){
                add = false;
                break;
            }
        }

        if(add)
            uniqueList.push_back(wordList[i]);
    }

    sort(uniqueList.begin(), uniqueList.end());
    for(int i = 0; i < uniqueList.size(); i++)
        cout << uniqueList[i] << endl;

    return 0;
}

void clearList(int list[])
{
    for(int i = 0; i < 26; i++)
        list[i] = 0;
}
bool isMatch(int list[])
{
    for(int i = 0; i < 26; i++)
        if(list[i] != 0)
            return false;
    return true;
}
