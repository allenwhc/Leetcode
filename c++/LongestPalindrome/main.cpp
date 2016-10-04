#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
*	Hash table solution
*	Time complexity: O(n)
*	Extra space: O(n)
*/
int longestPalindrome(string s){
	if(s.empty()) return 0;
	int res = 0;
	int largest_odd = 0;
	unordered_map<char,int> dict;
	for(char c:s) dict[c]++;
	for(auto it=dict.begin(); it!=dict.end(); ++it){
		if(it->second % 2==0) res += it->second;
		else{
			if(it->second > largest_odd){
				res += it->second - (largest_odd!=0);
				largest_odd = it->second;
			}
			else res += it->second - 1;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	cout << longestPalindrome(s) << endl;
	return 0;
}