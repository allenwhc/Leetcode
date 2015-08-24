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
		if (n == 0) return -1;
		else if (n == 1) return 0;
		else{
			vector<int> newGas(n), newCost(n);
			int i = 0;
			int index = 0;
			bool existStation; 
			while (i < n){
				bool canCircleOnce = true;
				existStation = true;
				int tank = 0;
				//Determines if the starting station qualifies
				if (gas[i] < cost[i]){
					i++;
					existStation = false;
					continue;
				}
				//Saves gas and cost to two new arrays
				for (int j = 0; j < n - i; j++){
					newGas[j] = gas[i + j];
					newCost[j] = cost[i + j];
				}
				for (int j = n - i; j < n; j++){
					newGas[j] = gas[j - n + i];
					newCost[j] = cost[j - n + i];
				}
				tank = newGas[0] - newCost[0];	//Intializes the gas left in tank
				for (int j = 1; j < n; j++){
					tank = tank + newGas[j] - newCost[j];
					if (tank < 0){
						canCircleOnce = false;
						break;
					}
				}
				if (!canCircleOnce) {
					existStation = false;
					i++;
				}
				else{
					index = i;
					break;
				}
			}
			if (existStation) return index;
			else return -1;
		}
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