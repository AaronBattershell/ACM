//**********************************************************************************************************
// Aaron Battershell
// 2/26/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=55
//**********************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;

struct People {
        string name;
        int moneyGiven;          //How much money that person gives
        int giftsGiven;          //How many gifts this person gives
        int netMoney;            //Net total of money given
        vector<string>givenList; //List of people who get gifts
};

int main()
{
    int totalPeople;
    int personIndex;
    bool print = false;
    string currentPerson;
    People list[10];

    while(cin >> totalPeople) {
        for(int i = 0; i < totalPeople; i++) {
            cin >> list[i].name;
            list[i].netMoney = 0;
        }

        //For every person....
        for(int i = 0; i < totalPeople; i++) {
            cin >> currentPerson;

            //Find the index currentPerson belongs to
            for(int n = 0; n < totalPeople; n++)
                if(list[n].name == currentPerson)
                    personIndex = n;
            cin >> list[personIndex].moneyGiven;
            cin >> list[personIndex].giftsGiven;

            //Get names of people who gifts are given to
            for(int n = 0; n < list[personIndex].giftsGiven; n++) {
                string temp;
                cin >> temp;
                list[personIndex].givenList.push_back(temp);
            }

            //For everyone to whom gifts were given, give them a proportional amount of money
            for(int n = 0; n < list[personIndex].givenList.size(); n++) {
                if(list[personIndex].moneyGiven == 0) break;
                for(int j = 0; j < totalPeople; j++)
                   if(list[personIndex].givenList[n] == list[j].name) {
                       list[j].netMoney += list[personIndex].moneyGiven / list[personIndex].giftsGiven;
                       break;
                    }
            }

            //Subtract the money a person gives from their net total
            if(list[personIndex].giftsGiven != 0)
                list[personIndex].netMoney -= list[personIndex].moneyGiven;
            //Add back the remainder of money rounded down
            if(list[personIndex].moneyGiven != 0 && list[personIndex].giftsGiven != 0)
                list[personIndex].netMoney += list[personIndex].moneyGiven - ((list[personIndex].moneyGiven / list[personIndex].giftsGiven) * list[personIndex].giftsGiven);
        }

        //Print out statistics
        if(print) cout << endl; print = true;
        for(int i = 0; i < totalPeople; i++)
            cout << list[i].name << " " << list[i].netMoney << endl;
    }

    return 0;
}
