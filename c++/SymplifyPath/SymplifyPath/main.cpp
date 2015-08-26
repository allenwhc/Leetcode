/*
*	Simplify Path
*	Last Modified: 7/13/2015
*/

#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
	string simplifyPath(string path){
		stack<string> myStack;
		int i = 0;
		while (i < path.length()){
			while (path[i] == '/' && i < path.length()) i++;	//Skip the first several '/'s
			if (i == path.length()) break;	//If path contains only '/'s break
			int begin = i;
			while (path[i] != '/' && i < path.length()) i++;
			int end = i - 1;	//Decide the end boundary
			string str = path.substr(begin, end - begin + 1);
			if (str == ".."){
				if (!myStack.empty()) myStack.pop();
			}
			else if (str != ".") myStack.push(str);
		}
		string result = "";
		if (myStack.empty()){
			result = "/";
			return result;
		}
		vector<string> catchStack;
		while (!myStack.empty()){
			catchStack.push_back(myStack.top());
			myStack.pop();
		}
		while (!catchStack.empty()){
			result += "/" + catchStack.back();
			catchStack.pop_back();
		}
		return result;
	}
};

void main(int argc, char *argv[]){
	Solution s;
	vector<string> paths = { "/a/./b/../../c/", "/../", "/home//foo/" };
	vector<string> simplify(paths.size(), "");
	for (int i = 0; i < paths.size(); i++)
		simplify[i] = s.simplifyPath(paths[i]);
	for (int i = 0; i < paths.size(); i++)
		cout << "The simplified path of '" << paths[i] << "' is: '" << simplify[i] << "'." << endl;
	system("pause");
}