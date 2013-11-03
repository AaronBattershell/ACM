//**********************************************************************************************************
// Aaron Battershell
// 11/2/13
// http://codeforces.com/problemset/problem/118/D
//**********************************************************************************************************
#include <map>
#include <iostream>
using namespace std;

struct armyInfo {
	armyInfo(int _man, int _horse, int _manConsec, int _horseConsec) {
		man = _man;
		horse = _horse;
		manConsec = _manConsec;
		horseConsec = _horseConsec;
	}
	int man, horse, manConsec, horseConsec;

	bool operator < (const armyInfo& n) const {
		if (man == n.man && horse == n.horse && manConsec == n.manConsec) {
			return horseConsec < n.horseConsec;
		} else if (man == n.man && horse == n.horse) {
			return manConsec < n.manConsec;
		} else if (man == n.man) {
			return horse < n.horse;
		} else {
			return man < n.man;
		}
	}
};

int getMaxPermu(map<armyInfo, int> &dp, armyInfo army, int menLimit, int horseLimit) {
	if (army.man < 0 || army.horse < 0 || army.manConsec > menLimit || army.horseConsec > horseLimit) {
        	return 0;
	} else if (army.man == 0 && army.horse == 0) {
        	return 1;
	} else if (dp.count(army)) {
        	return dp[army];
	} else {
		armyInfo armyMan(army.man-1, army.horse, army.manConsec+1, 0); 
		armyInfo armyHorse(army.man, army.horse-1, 0, army.horseConsec+1);
    
        	dp[army] = (getMaxPermu(dp, armyMan, menLimit, horseLimit) + getMaxPermu(dp, armyHorse, menLimit, horseLimit)) % 100000000;
        	return dp[army];
    	}
}

int main() {
	map<armyInfo, int> dp;
	int menCount, horseCount, menLimit, horseLimit;
	cin >> menCount >> horseCount >> menLimit >> horseLimit;

	armyInfo army(menCount, horseCount, 0, 0);

	cout << getMaxPermu(dp, army, menLimit, horseLimit);
	return 0;
}
