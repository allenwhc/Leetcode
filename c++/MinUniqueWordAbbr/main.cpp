#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string minAbbreviation(string target, vector<string>& dictionary){
	if(target.empty() || find(dictionary.begin(), dictionary.end(), target) != dictionary.end()) return "";
	
}

int main(int argc, char const *argv[])
{
	string target = "apple";
	vector<string> dictionary = {"plain","amber","blade"};
	return 0;
}