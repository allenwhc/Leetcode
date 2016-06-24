/*
*	String to Integer
*	Last Modified: 7/24/2015
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int negative = 1;
        int num = 0;
        int s = str.find_first_not_of(' '), e = str.find_last_not_of(' ');
        str = str.substr(s, e-s+1); //trim leading and trailing ' '
        for(int i=0; i<str.size(); i++){
            if(str[i] == '+' || str[i] == '-'){
                if(i==0) negative = str[i] == '-'? -1:1;
                else return negative*num;
            }
            else if(str[i] >= '0' && str[i] <= '9'){
                int cum = num*10 + (str[i] - '0');
                if(num >= INT_MAX/10 && str[i]-'0'>=8 || cum/10 != num)
                    return negative==1?INT_MAX:INT_MIN;
                num = cum;
            }
            else return negative*num;
        }
        return negative*num;
    }
};

void main(int argc, char *argv[]){
	//string str = "    -243214&*(3892uhi  asd92032d";
	string str = "2147483648";
	Solution s;
	cout << "Converting '" << str << "' to integer is: " << s.myAtoi(str) << endl;
	system("pause");
}