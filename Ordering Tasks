//**********************************************************************************************************
// Aaron Battershell
// 3/9/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
//**********************************************************************************************************
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct task {
    vector<int>connections;
};

int main()
{
    task* list;
    int taskCount, relationCount;
    int before, after;
    bool placed, space;
    vector<int> toDoList;

    while(true) {
        cin >> taskCount;
        cin >> relationCount;
        if(taskCount == 0 && relationCount == 0)
            break;
        toDoList.clear();
        space = false;

        list = new task[taskCount];
        for(int i = 0; i < relationCount; i++) {
            cin >> before;
            cin >> after;
            list[before-1].connections.push_back(after);
        }
        for(int i = 0; i < list[i].connections.size(); i++)
            sort(list[i].connections.begin(), list[i].connections.end());

        for(int i = 0; i < taskCount; i++) {
            placed = false;
            if(list[i].connections.size() == 0 || toDoList.size() == 0)
                toDoList.push_back(i+1);

            else {
                for(int n = 0; n < list[i].connections.size(); n++) {
                    for(int j = 0; j < toDoList.size(); j++) {
                        if(list[i].connections[n] == toDoList[j]) {
                            toDoList.insert(toDoList.begin() +j, i+1);
                            placed = true;
                            break;
                        }
                        else if(j == toDoList.size()-1 && n == list[i].connections.size()-1) {
                            toDoList.push_back(i+1);
                            placed = true;
                            break;
                        }
                    }
                    if(placed)
                        break;
                }
            }
        }

        for(int i = 0; i < taskCount; i++) {
            if(space)
                cout << " ";
            space = true;
            cout << toDoList[i];
        }
        cout << endl;

        delete [] list;
    }

    return 0;
}
