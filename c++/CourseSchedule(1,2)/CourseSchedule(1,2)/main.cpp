/*
*	Course Schedule I & II
*	Last Modified: 7/9/2015
*/

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class Solution{
public:
	//Course Schedule I, check if one can finish all the courses
	//BFS
	bool canFinish(int numCourses, vector <pair<int, int>>& prerequisites){
		int n = prerequisites.size();
		vector<int> numOfPrerequisites(numCourses);

		if (n == 0 || numCourses == 0) return true;

		//Count number of prerequisites
		for (int i = 0; i < n; i++)
			numOfPrerequisites[prerequisites[i].first]++;

		//Store courses that have no prerequisites
		queue<int> noPrerequisites;
		for (int i = 0; i < numCourses; i++){
			if (numOfPrerequisites[i] == 0) noPrerequisites.push(i);
		}

		//Stores number of courses that have no prerequisites
		int noOfNonPre = noPrerequisites.size();

		while (!noPrerequisites.empty()){	//While the queue is not empty
			int top = noPrerequisites.front();	//Gets the first element in the queue
			noPrerequisites.pop();	//Delete the first element in the queue
			for (int i = 0; i < n; i++){
				if (prerequisites[i].second == top){
					numOfPrerequisites[prerequisites[i].first]--;
					if (numOfPrerequisites[prerequisites[i].first] == 0){
						noOfNonPre++;
						noPrerequisites.push(prerequisites[i].first);
					}
				}
			}
		}
		return noOfNonPre==numCourses;
	}

	//Course Schedule II, find courses taken order in order to finish them all
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites){
		int lenOfPrerequisites = prerequisites.size();
		vector<int> result(numCourses);
		
		//If there is no prerequisites at all
		if (lenOfPrerequisites == 0){
			for (int i = 0; i < numCourses; i++)
				result[i] = i;
			return result;
		}

		//Count the number of prerequistes for different courses
		vector<int> noPreDiffCourses(numCourses);
		for (int i = 0; i < lenOfPrerequisites; i++)
			noPreDiffCourses[prerequisites[i].first]++;

		//Store courses that have no prerequisites
		queue<int> courseNoPre;
		for (int i = 0; i < numCourses; i++){
			if (noPreDiffCourses[i] == 0) courseNoPre.push(i);
		}

		//Initialize the number of non prerequisites courses
		int numNoPre = courseNoPre.size();
		int j = 0;

		while (!courseNoPre.empty()){
			int top = courseNoPre.front();
			courseNoPre.pop();
			result[j++] = top;
			for (int i = 0; i < lenOfPrerequisites; i++){
				if (prerequisites[i].second == top){
					noPreDiffCourses[prerequisites[i].first]--;
					if (noPreDiffCourses[prerequisites[i].first] == 0){
						numNoPre++;
						courseNoPre.push(prerequisites[i].first);
					}
				}
			}
		}

		//In case there is a loop in the graph
		vector<int> noResult;

		if (numNoPre == numCourses) return result;
		else return noResult;
	}

};

void main(int argc, char* argv[]){
	pair<int, int> pre1 = make_pair(1, 0), pre2 = make_pair(2, 0), pre3 = make_pair(3, 1), pre4 = make_pair(3, 2);
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(pre1);
	prerequisites.push_back(pre2);
	prerequisites.push_back(pre3);
	prerequisites.push_back(pre4);
	int numCourses = 4;
	Solution s;
	vector<int> courseOrder = s.findOrder(numCourses, prerequisites);
	if (s.canFinish(numCourses, prerequisites)){
		cout << "Can finish the course!" << endl;
		cout << "The order to take courses is: ";
		for (int i = 0; i < courseOrder.size(); i++){
			cout << courseOrder[i];
			if (i != courseOrder.size() - 1) cout << "->";
		}
		cout << endl;
	}
	else cout << "Can't finish the course!" << endl;
	system("pause");
}