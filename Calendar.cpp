//**********************************************************************************************************
// Aaron Battershell
// 6/25/13
// http://codeforces.com/problemset/problem/304/B
//**********************************************************************************************************
#include <iostream>
#include <sstream>
using namespace std;

static int nMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int lMonths[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int year, month, day;

    Date(string time) {
        year = strToInt(time, 0, 4);
        month = strToInt(time, 5, 2);
        day = strToInt(time, 8, 2);
    }

    bool isLeap(int x) {
        return (!(x%4) && (x%100 || !(x%400)));
    }

    int strToInt(string str, int pos, int len) {
        int newInt;
        stringstream ss;
        string temp(str, pos, len);

        ss << temp;
        ss >> newInt;
        return newInt;
    }

    int operator < (Date &_d2) {
        if(year != _d2.year)
            return (year < _d2.year ? 0 : 1);
        else if(month != _d2.month)
            return (month < _d2.month ? 0 : 1);
        else if(day != _d2.day)
            return (day < _d2.day ? 0 : 1);
        else
            return 2;
    }

    int diff(Date &d2) {
        int dayCount = 0, nYears = 0, lYears = 0;

        if(year != d2.year) {
            for(int i = year+1; i < d2.year; ++i)
                (isLeap(i) ? lYears : nYears)++;
            dayCount += lYears*366 + nYears*365;

            //Calc beg date -> end of first year
            dayCount += (isLeap(year) ? lMonths[month-1]-day : nMonths[month-1]-day);
            for(int i = month+1; i <= 12; ++i)
                dayCount += (isLeap(year) ? lMonths[i-1] : nMonths[i-1]);

            //Calc last year -> end date
            dayCount += d2.day; 
            for(int i = 1; i <= d2.month-1; ++i)
                dayCount += (isLeap(d2.year) ? lMonths[i-1] : nMonths[i-1]);
        }
        else if (year == d2.year) {
            dayCount += (month == d2.month ? d2.day-day : (isLeap(year) ? lMonths[month-1]-day : nMonths[month-1]-day) + d2.day);
            for(int i = month+1; i < d2.month; ++i)
                dayCount += (isLeap(year) ? lMonths[i-1] : nMonths[i-1]);
        }

        return dayCount;
    }
};

int main() {
    string d1, d2;
    cin >> d1 >> d2;

    Date time1(d1), time2(d2);
    cout << (time1<time2==0 ? time1.diff(time2) : (time1<time2==1 ? time2.diff(time1) : 0));
    return 0;
}
