//**********************************************************************************************************
// Aaron Battershell
// 3/6/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1520
//**********************************************************************************************************
#include <iostream>
using namespace std;

class Fibonacci {
    private:
        string fibList[10000];

    public:
        string getFib(int x) { return fibList[x-1]; }
        void generateList();
};

void Fibonacci::generateList() {
    string temp;
    fibList[0] = "1";
    fibList[1] = "1";

    for(int i = 2; i < 10000; i++) {
        string str1 = fibList[i-1];
        string str2 = fibList[i-2];

        if(str1.length() != str2.length()) {
            temp = "";
            for(int n = 0; n < str1.length() - str2.length(); n++)
                temp += "0";
            temp += str2;
            str2 = temp;
        }

        temp = "";
        int sum, carry;
        sum = carry = 0;
        for(int n = str1.length()-1; n >= 0; n--) {
            sum = 0;
            sum += carry;
            carry = 0;

            sum += str1[n] - '0';
            sum += str2[n] - '0';

            if(sum >= 10) {
                carry++;
                sum -= 10;
            }

            temp += sum + '0';
            if(n == 0 && carry == 1)
                temp += "1";
        }

        fibList[i] = "";
        for(int n = temp.length()-1; n >= 0; n--)
            fibList[i] += temp[n];
    }
}

int main() {
    int index;
    Fibonacci list;
    list.generateList();

    while(cin >> index)
        cout << list.getFib(index) << endl;

    return 0;
}
