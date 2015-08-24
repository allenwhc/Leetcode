/*
*	The Skyline Problem
*	Last Modified: 7/15/2015
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution{
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
		vector<pair<int, int>> skyline;
		if (buildings.size() == 0 || buildings[0].size() == 0) return skyline;
		skyline = findSkyline(buildings, 0, buildings.size() - 1);

		//Delete skyline point with the same height
		for (int i = 0; i < skyline.size(); i++){
			if (i>0 && skyline[i].second == skyline[i - 1].second){
				skyline.erase(skyline.begin() + i);
				i--;
			}
		}
		return skyline;
	}
	vector<pair<int,int>> findSkyline(vector<vector<int>>& buildings, int start, int end){
		if (start == end){
			vector<pair<int, int>> res;
			res.push_back(make_pair(buildings[start][0], buildings[start][2]));
			res.push_back(make_pair(buildings[start][1], 0));
			return res;
		}
		int mid = (start + end) / 2;
		vector<pair<int, int>> l1 = findSkyline(buildings, start, mid);
		vector<pair<int, int>> l2 = findSkyline(buildings, mid + 1, end);
		return merge(l1, l2);
	}

	vector<pair< int, int>> merge(vector<pair<int, int>>& l1, vector<pair<int, int>>& l2){
		vector<pair<int, int>> res;
		int i = 0, j = 0, h1 = 0, h2 = 0;
		while (i < l1.size() && j < l2.size()){
			if (l1[i].first < l2[j].first){
				h1 = l1[i].second;
				res.push_back(make_pair(l1[i].first, max(h1, h2)));
				i++;
			}
			else if (l1[i].first > l2[j].first){
				h2 = l2[j].second;
				res.push_back(make_pair(l2[j].first, max(h1, h2)));
				j++;
			}
			else{
				h1 = l1[i].second;
				h2 = l2[j].second;
				res.push_back(make_pair(l1[i].first, max(h1, h2)));
				i++;
				j++;
			}
		}

		//Add the left elements to result
		while (i < l1.size()){
			res.push_back(make_pair(l1[i].first, l1[i].second));
			i++;
		}
		while (j < l2.size()){
			res.push_back(make_pair(l2[j].first, l2[j].second));
			j++;
		}
		return res;
	}

};

void main(int argc, char* argv[]){
	vector<vector<int>> buildings = { { 2, 9, 10 }, { 3, 7, 15 }, { 5, 12, 12 }, { 15, 20, 10 }, { 19, 24, 8 } };
	Solution s;
	cout << "The positions of buildings are: " << endl;
	for (int i = 0; i < buildings.size(); i++){
		cout << "Building " << i + 1 << ": ";
		for (int j = 0; j < buildings[i].size(); j++){
			if (j == 0) cout << "Left=" << buildings[i][j] << ", ";
			else if (j == 1) cout << "Right=" << buildings[i][j] << ", ";
			else cout << "Height=" << buildings[i][j];
		}
		cout << endl;
	}
	vector<pair<int, int>> skyline = s.getSkyline(buildings); 
	cout << "The skyline is: " << endl;
	for (int i = 0; i < skyline.size(); i++){
		cout << "(" << skyline[i].first << ", " << skyline[i].second << ")";
		if (i != skyline.size() - 1) cout << ", ";
	}
	cout << endl;
	system("pause");
}