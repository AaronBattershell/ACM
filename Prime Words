//**********************************************************************************************************
// Aaron Battershell
// 3/1/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1865
//**********************************************************************************************************

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

void getPrimes(bool [], int);

int main() {
    string phrase;
    int sum;
    const int SIZE = 1050;
    bool primes[SIZE];
    getPrimes(primes, SIZE);

    while(cin >> phrase) {
        sum = 0;
        for(int i = 0; i < phrase.length(); ++i)
            sum += (islower(phrase[i]) ? phrase[i] - 'a' + 1 : phrase[i] - 'A' + 27);
        cout << (primes[sum] == true ? "It is a prime word." : "It is not a prime word.") << endl;
    }

    return 0;
}

void getPrimes(bool list[], int size) {
    for(int i = 0; i < size; ++i)
        list[i] = true;

    list[0] = false;
    for(int i = 2; i < size; ++i) {
        if(!list[i])
            continue;
        for(int n = i+i; n < size; n += i)
            list[n] = false;
    }
}
