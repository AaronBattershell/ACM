//**********************************************************************************************************
// Aaron Battershell
// 3/3/13
// uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638
//**********************************************************************************************************



#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct GroupList {
    GroupList() { infected = false; }
    bool infected;
    vector<int> people;
};

int main()
{
    int peopleCount;
    int peoplePerGroup;
    int groups;
    GroupList *list;
    vector<int> infectedList;

    while(true) {
        cin >> peopleCount >> groups;
        if(peopleCount == 0 && groups == 0) break;
        if(groups == 0) { cout << 1 << endl; continue; }
        list = new GroupList[groups];

        for(int i = 0; i < groups; i++) {
            cin >> peoplePerGroup;
            for(int n = 0; n < peoplePerGroup; n++) {
                int temp;
                cin >> temp;
                list[i].people.push_back(temp);
            }
            sort(list[i].people.begin(), list[i].people.end());
        }

        //Find infected
        infectedList.clear();
        infectedList.push_back(0);
        while(true) {
            bool changed = false;
            for(int i = 0; i < groups; i++) {                       //For every group..
                if(list[i].infected == true) continue;
                for(int n = 0; n < list[i].people.size(); n++) {    //For every person in a group...
                    for(int j = 0; j < infectedList.size(); j++) {  //For every infected person found...
                        if(list[i].people[n] == infectedList[j]) {  //Infected found
                            changed = true;
                            list[i].infected = true;

                            //Include members of this list to infected list
                            for(int h = 0; h < list[i].people.size(); h++)
                                infectedList.push_back(list[i].people[h]);
                            break;
                        }
                        if(changed) break;
                    }
                    if(changed) break;
                }
            }

            if(!changed) break;
        }
        sort(infectedList.begin(), infectedList.end());
        for(int i = infectedList.size()-1; i > 0; i--)
            if(infectedList[i] == infectedList[i-1])
                infectedList.erase(infectedList.begin() + i);


        cout << infectedList.size() << endl;
        delete [] list;
    }

    return 0;
}
