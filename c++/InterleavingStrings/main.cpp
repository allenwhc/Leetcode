#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isInterleave(string s1, string s2, string s3){
	int m = s1.size(), n = s2.size(), l = s3.size();
	if(m+n!=l) return false;
	if(!m) return !s2.compare(s3);
	if(!n) return !s1.compare(s3);
	vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			int idx = i+j-1;
			if(!i && !j) {dp[i][j] = true;continue;}
			cout<<idx<<endl;
			if(!i){
				if(s3[idx] == s2[j-1]) dp[i][j] = dp[i][j-1];
			}
			else if(!j){

				if(s3[idx] == s1[i-1]) dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = (s3[idx] == s1[i-1]?dp[i-1][j]:false) | (s3[idx] == s2[j-1]?dp[i][j-1]:false);
 			}
		}
	}
	for(vector<bool> v:dp){
		for(bool b:v) cout <<b<<" ";
		cout<<endl;
	}
	return dp[n][m];
}

int main(int argc, char const *argv[])
{
	string s1 = "aabaac",s2="aadaaeaaf",s3="aadaaeaabaafaac";
	cout << isInterleave(s1,s2,s3) << endl;
	return 0;
}