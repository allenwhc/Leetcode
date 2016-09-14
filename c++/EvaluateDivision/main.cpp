#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

bool calculate(map<string,map<string, double>>& dict, vector<double> ret, double curr, string dividend, string divisor, set<string> visited){
	//cout << dividend << "," << divisor << endl;
	for(auto t=visited.begin(); t!=visited.end(); t++)
			cout <<*t << " ";
		cout << endl;
	if(dict.find(dividend) == dict.end() || dict.find(divisor) == dict.end() || visited.find(dividend) != visited.end()) return false;

	cout << "dividend:" << dividend << ", divisor: " << divisor<<endl;
	if(dividend.compare(divisor)==0){ret[0]=curr; return true;}
	visited.insert(dividend);
	for(auto it=dict[dividend].begin(); it!=dict[dividend].end(); ++it){
		
		cout << it->first << ", " << divisor << endl;
		//cout <<curr << "," << it->second << endl;
		if(calculate(dict, ret, curr*it->second, it->first, divisor, visited)) return true;
		cout << endl;
	}
	visited.erase(dividend);
	return false;
}

vector<double> calcEquation(vector<pair<string,string>>& equations, vector<double>& values, vector<pair<string,string>> query){
	map<string, map<string,double>> dict;
	vector<double> res(query.size(), 0.0);
	for(int i=0; i<equations.size(); i++){
		dict[equations[i].first][equations[i].second] = values[i];
		dict[equations[i].second][equations[i].first] = 1 / values[i];
	}
	for(int i=0; i<query.size(); i++){
		vector<double> ret = {1.0};
		set<string> visited;
		res[i] = (calculate(dict, ret, 1.0, query[i].first, query[i].second, visited))?ret[0]:-1.0;
	}
	for(auto it=dict.begin(); it!=dict.end(); ++it){
		cout << it->first<< ":"<<endl;
		for(auto i=it->second.begin(); i!=it->second.end(); ++i)
			cout << i->first <<":" <<i->second << endl;
		cout <<endl;

	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<pair<string,string>> equations = {{"a","b"}, {"b","c"}};
	vector<double> values = {2.0, 3.0};
	vector<pair<string,string>> query = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	vector<double> res = calcEquation(equations, values, query);
	for(auto x: res) cout << x << " ";

	return 0;
}