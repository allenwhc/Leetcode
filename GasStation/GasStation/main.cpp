/*
*	Gas Station
*	Last Modified: 6/18/2015
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int canCompleterCircuit(vector<int>& gas, vector<int>& cost){
		int n = gas.size();
		vector<int> tank(n);
		for (int i = 0; i < n; i++)
			tank[i] = gas[i] - cost[i];		//Calculates the difference between gas and cost on each and every station
		int sum = 0, leftGas = 0, startStation = 0;
		for (int i = 0; i < n; i++){
			leftGas += tank[i];
			sum += tank[i];
			if (sum < 0){
				startStation = i + 1;
				sum = 0;
			}
		}
		if (leftGas < 0) return -1;
		else return startStation;
	}
};

void main(int argc, char *argv[]){
	vector<int> gas = { 3, 4, 6, 5, 4 };
	vector<int> cost = { 5, 2, 7, 3, 5 };
	Solution s;
	int index = s.canCompleterCircuit(gas, cost);
	cout << "From gas station No." << index << ", one can finish the journey" << endl;
	system("pause");
}