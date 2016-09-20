#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution{
	//CONSTRUCT MAP
	// map<int,set<string>> constructDict(vector<int>& base, int target){
	// 	map<int,set<string>> dict;
	// 	vector<vector<int>> dp(base.size(), vector<int>(target+1, -1));
	// 	dp[0][base[0]] = 1;
	// 	dict[1].insert(target==11?"1":"01");
	// 	for(int i=0; i<dp.size(); i++) dp[i][0] = 0;
	// 	for(int i=1; i<dp.size(); i++){
	// 		for(int j=1; j<=target; j++){
	// 			if(base[i] > j) dp[i][j] = dp[i-1][j];
	// 			else{
	// 				if(dp[i-1][j-base[i]] != -1){
	// 					dp[i][j] = dp[i-1][j-base[i]] + 1; 
	// 					string curr_num;
	// 					if(j<=9 && target==59) curr_num = "0";
	// 					curr_num.append(to_string(j));
	// 					//if(dict.find(dp[i-1][j-base[i]]+1) == dict.end())
	// 					dict[dp[i-1][j-base[i]]+1].insert(curr_num);
						
	// 				}
	// 			}
	// 		}
	// 	}
	// 	return dict;
	// }

	void helper(vector<string>& res, int idx, string time, vector<vector<string>>& vec){
		if(idx == vec.size()){
			time.pop_back();
			res.push_back(time);
			return;
		}
		for(int i=0; i<vec[idx].size(); ++i)
		{	
			helper(res,idx+1,time+vec[idx][i]+":",vec);
		}
	}
public:
	vector<string> readBinaryWatch(int num){
		vector<string> res;
		if(num<=0 || num>8) return res;
		map<int, vector<string>> hours = {{0,{"0"}},
									{1,{"1","2","4","8"}},
									{2,{"3","5","6","9","10"}},
									{3,{"7","11"}}};
		map<int, vector<string>> minutes = {{0,{"00"}},
									{1,{"01","02","04","08","16","32"}},
									{2,{"03","05","06","09","10","12","17","18","20","24","33","34","36","40","48"}},
									{3,{"07","11","13","14","19","21","22","25","26","28","35","37","38","41","42","44","49","50","52","56"}},
									{4,{"15","23","27","29","30","39","43","45","46","51","53","54","57","58"}},
									{5,{"31","47","55","59"}}};
		// vector<int> hour_base = {1,2,4,8};
		// vector<int> minute_base = {1,2,4,8,16,32};
		// map<int,set<string>> hours = constructDict(hour_base, 11);
		// map<int,set<string>> minutes = constructDict(minute_base, 59);
		// hours[0].insert("0");
		// minutes[0].insert("00");
		// cout << "hours:" << endl;
		// for(auto it=hours.begin(); it!=hours.end();++it){
		// 	cout << it->first << ": ";
		// 	for(auto& v:it->second) cout << v << " ";
		// 	cout << endl;
		// }
		// cout << "minutes:" << endl;
		// for(auto it=minutes.begin(); it!=minutes.end();++it){
		// 	cout << it->first << ": ";
		// 	for(auto& v:it->second) cout << v << " ";
		// 	cout << endl;
		// }
		for(int i=0; i<=min(3,num); i++){
			vector<string> temp;
			vector<vector<string>> vec;
			vec.push_back(hours[i]);
			vec.push_back(minutes[num-i]);
			helper(temp, 0, "", vec);
			//for(auto& v: temp) cout << v << " ";
			//cout << endl;
			copy(temp.begin(),temp.end(),back_inserter(res));
		}
		return res;
	}
};


int main(int argc, char const *argv[])
{
	int num = 2;
	Solution sol;
	for(auto& x:sol.readBinaryWatch(num))
		cout << x << endl;
	return 0;
}