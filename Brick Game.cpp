//**********************************************************************************************************
// Aaron Battershell
// 2/25/13
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2986
//**********************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cases;
    int playerCount;
    vector<int>list;

    cin >> cases;
  	for(int i = 0; i < cases; i++)
  	{
    		cin >> playerCount;
    		list.clear();
    
    		for(int n = 0; n < playerCount; n++) {
      		  int temp;
      			cin >> temp;
      			list.push_back(temp);
    		}
  
        cout << "Case " << i+1 << ": " << list[playerCount/2] << endl;
  	}

	  return 0;
}
