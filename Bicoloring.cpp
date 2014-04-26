//**********************************************************************************************************
// Aaron Battershell
// 2/22/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
//**********************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int nodeCount = 1;
    int cinCount;
    int node1;
    int node2;
    char chart[200][200];

    bool remove;         //Element to be removed from check
    bool overload;       //Imposible graph if true
    vector<int> check;   //Holds node indexes that need to be checked


    while(true)
    {
        cin >> nodeCount;
        if(nodeCount == 0)
            break;

        overload = false;
        cin >> cinCount;

        //Clear node chart
        for(int i = 0; i < nodeCount; i++) {
            check.push_back(i);
            for(int n = 0; n < nodeCount; n++)
                chart[i][n] = '0';
        }

        //Get nodes and eddit the node chart
        for(int i = 0; i < cinCount; i++) {
            cin >> node1;
            cin >> node2;

            chart[node1][node2] = '1';
            chart[node2][node1] = '1';
        }

        //Assign each existing node a color
        chart[0][0] = 'R';
        while(check.size() != 0) {

            for(int i = 0; i < check.size(); i++) {
                remove = false;

                for(int n = 0; n < nodeCount; n++) {
                    if(chart[check[i]][n] == '1') {
                        if(chart[check[i]][check[i]] == '0')
                            break;
                        else {
                            remove = true;
                            chart[check[i]][n] = (chart[check[i]][check[i]] == 'R' ? 'G' : 'R');
                        }

                        if(chart[n][n] == '0')
                            chart[n][n] = chart[check[i]][n];
                        else if(chart[n][n] != chart[check[i]][n]) {
                            overload = true;
                            break;
                        }
                    }
                }

                if(remove)
                    check.erase(check.begin() + i);
                if(overload == true) {
                    check.clear();
                    break;
                }
            }
        }

        cout << (overload ? "NOT BICOLORABLE." : "BICOLORABLE.") << endl;
    }

    return 0;
}
