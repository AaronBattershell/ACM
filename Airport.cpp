//**********************************************************************************************************
// Aaron Battershell
// 9/20/13
// http://codeforces.com/problemset/problem/218/B
//**********************************************************************************************************
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int people, peopleHolder,  planeCount, min, max;
	vector<int> planeList;

	people = peopleHolder = planeCount = min = max = 0;
	cin >> peopleHolder >> planeCount;

	for(int i = 0; i < planeCount; i++) {
		int temp;
		cin >> temp;
		planeList.push_back(temp);
	}


	//Calculate Minimum Profit
	sort(planeList.begin(), planeList.end());
	people = peopleHolder;
	for(int i = 0; i < planeCount && people != 0; i++) {
		if(people <= planeList[i]) {
			min += planeList[i]*(planeList[i]+1)/2 - (planeList[i]-people)*(planeList[i]-people+1)/2;
			people = 0;
		}
		else {
			min += planeList[i]*(planeList[i]+1)/2;
			people -= planeList[i];
		}
	}

	
	//Calculate Maximum Profit
	sort(planeList.rbegin(), planeList.rend());
	people = peopleHolder;
	for(int i = 0; i < planeCount && people != 0 && planeCount != 1;) {
		for(int n = 0; n < planeCount && people != 0; n++) {
			if (n == 0)
				while(planeList[0] >= planeList[1] && people != 0) {
					max += planeList[0]--;
					people--;
				}
			else
				while(planeList[n] > planeList[n-1] && people != 0)  {
					max += planeList[n]--;
					people--;
				} 
		}		
	}
	if(planeCount == 1) {
		max = min;
	}


	cout << max << " " << min;
	return 0;
}
