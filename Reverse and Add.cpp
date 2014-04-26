//**********************************************************************************************************
// Aaron Battershell
// 2/22/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=959
//**********************************************************************************************************

#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int strToInt(string);
string intToStr(unsigned long long int);

int main()
{
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++)
    {
        string primaryNum;
        string reverseNum;
        unsigned long long int sum = 0;
        int switches = 0;
        bool found;

        cin >> primaryNum;
        while(true)
        {
            sum = 0;
            found = false;
            reverseNum = "";

            //Check for palendrome
            if(primaryNum.length() == 1) {
                found = true;
                break;
            }
            for(int n = 0; n < primaryNum.length()/2; n++) {
                if(primaryNum[n] == primaryNum[primaryNum.length()-1 -n]) {
                    if(n == primaryNum.length()/2 -1) {
                        found = true;
                        break;
                    }
                }
                else
                    break;
            }
            if(found == true)
                break;

            //Make reverse of primary
            switches++;
            for(int n = 0; n < primaryNum.length(); n++)
                reverseNum += primaryNum[primaryNum.length()-1 -n];

            //Add primary and reverse, resulting in a new primary
            sum += strToInt(primaryNum);
            sum += strToInt(reverseNum);
            primaryNum = intToStr(sum);
        }

        cout << switches << " " << primaryNum << endl;
    }

    return 0;
}

unsigned long long int strToInt(string Snum)
{
    unsigned long long int total = 0;
    for(int i = 0; i < Snum.length(); i++)
        total += (Snum[i] - '0') * pow(10,Snum.length()-1 -i);

    return total;
}

string intToStr(unsigned long long int Inum)
{
    int power;
    int goTo;
    string placeHolder = "";

    for(int i = 0; true; i++) {
        if(Inum == pow(10, i)) {
            power = i;
            break;
        }
        else if(Inum < pow(10,i)) {
            power = i-1;
            break;
        }
    }

    goTo = power;
    for(int i = 0; i <= goTo; i++, power--) {
        placeHolder += (Inum / pow(10, power)) + '0';
        Inum -= pow(10, power) * static_cast<int>(Inum / pow(10, power));
    }

    return placeHolder;
}
