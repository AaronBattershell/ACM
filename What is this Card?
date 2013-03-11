//**********************************************************************************************************
// Aaron Battershell
// 3/11/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1587
//**********************************************************************************************************
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cases;
    int x, y;
    int cardIndex;
    string currentCard;
    vector<string> deck;

    cin >> cases;
    for(int i = 0; i < cases; i++) {
        deck.clear();
        y = 0;

        //Input
        for(int n = 0; n < 52; n++) {
            cin >> currentCard;
            deck.push_back(currentCard);
        }

        cardIndex = 26;
        for(int n = 0; n < 3; n++) {
            currentCard = deck[cardIndex];
            x = (isupper(currentCard[0]) ? 10 : currentCard[0] - '0');
            y +=  x;

            for(int j = 0; j <= 10-x; j++) {
                deck.erase(deck.begin() + cardIndex);
                cardIndex--;
            }
        }

        cout << "Case " << i+1 << ": " << deck[y-1] << endl;
    }

    return 0;
}
