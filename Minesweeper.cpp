//**********************************************************************************************************
// Aaron Battershell
// 2/22/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130
//**********************************************************************************************************

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    char temp;
    int caseCount = 0;
    bool space = false;

    while(true)
    {
        caseCount++;
        int down;
        int over;
        char board[102][102];

        cin >> down;
        cin >> over;
        if(over == 0 && down == 0)
            break;

        if(space)
            cout << endl;
        space = true;

        //clear board
        for(int i = 0; i < over + 2; i++)
            for(int n = 0; n < down + 2; n++)
                board[i][n] = '0';

        //Input info
        for(int i = 0; i < down; i++)
            for(int n = 0; n < over; n++) {
                cin >> temp;
                if (temp == '*')
                    board[i+1][n+1] = temp;
            }

        //Count how many mines are near by
        for(int i = 0; i < down; i++)
            for(int n = 0; n < over; n++) {
                if(board[i+1][n+1] != '*')
                    continue;

                if(board[i+2][n] != '*')   board[i+2][n] += 1;
                if(board[i+2][n+1] != '*') board[i+2][n+1] += 1;
                if(board[i+2][n+2] != '*') board[i+2][n+2] += 1;
                if(board[i+1][n+2] != '*') board[i+1][n+2] += 1;
                if(board[i][n+2] != '*')   board[i][n+2] += 1;
                if(board[i][n+1] != '*')   board[i][n+1] += 1;
                if(board[i][n] != '*')     board[i][n] += 1;
                if(board[i+1][n] != '*')   board[i+1][n] += 1;
            }

        cout << "Field #" << caseCount << ":" << endl;
        for(int i = 0; i < down; i++) {
            for(int n = 0; n < over; n++)
                cout << board[i+1][n+1];
            cout << endl;
        }
    }

    return 0;
}
