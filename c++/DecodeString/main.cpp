#include <string>
#include <stack>
#include <iostream>
using namespace std;


string decodeString(string s){
	if(s.empty()) return "";
	string res = "";
	int i = 0;
	stack<int> repeat;
	stack<string> strStack;
	while(i<s.size()){
		if(isdigit(s[i])){
			int count = 0;
			while(i<s.size() && isdigit(s[i])){
				count = count*10+(s[i]-'0');
				i++;
			}
			repeat.push(count);
		}else if(s[i] == '['){
			strStack.push(res);
			res = "";
			i++;
		}else if(s[i] == ']'){
			string str = "";
			int curr_repeat = repeat.top();
			repeat.pop();
			string curr_str = strStack.top();
			strStack.pop();
			for(int j=0; j<curr_repeat; j++)
				curr_str.append(res);
			res = curr_str;
			i++;
		}else{
			res.push_back(s[i++]);
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	string s = "2[abc]3[cd]ef";
	cout << decodeString(s) << endl;
	return 0;
}