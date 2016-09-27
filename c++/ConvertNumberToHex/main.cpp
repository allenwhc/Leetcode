#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

string toHex(int num){
	if(num == 0) return "0";
	else if(num == INT_MIN) return "80000000";
	string dict = "0123456789abcdef0";
	string res = "";
	int sign = num>0?1:-1;
	num *= sign;
	while(num!=0){
		int prev_num = num;
		num = (num / 16) * 16;

		int remainder = prev_num - num;
		res += dict[remainder];
		num /= 16;
		//cout << num << "," << remainder << endl;
	}
	if(sign == -1){	
		int carry = 0;
		for(int i=0; i<res.size(); i++){
			int temp = i==0 ;
			if(res[i]>='0' && res[i]<='9') 
				temp += 15 - (res[i] - '0');
			else
				temp += 15 - (res[i] - 'a' + 10);
			temp += carry;
			carry = temp / 16;
			res[i] = dict[temp];
		}
		for(int i=res.size();i<8;i++)
			res.push_back('f');
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums = {26,-100000,INT_MIN,INT_MAX,45,-145,4512};
	for(int num:nums){
		cout << num << " -> " << toHex(num) << endl;
	}
	cout << 'f' - 'e' << endl;
	return 0;
}