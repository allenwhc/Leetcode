#include <iostream>
#include <deque>
#include <string>
using namespace std;

string parseTernary(string expression){
	if(expression.empty()) return "";
	deque<char> stack;
	for(int i=expression.size()-1; i>=0; --i){
		if(!stack.empty() && stack.front() == '?'){
			stack.pop_front();	//pop '?'
			char _true = stack.front();
			stack.pop_front();	//pop true element 
			stack.pop_front();	//pop ':'
			char _false = stack.front();
			stack.pop_front();	//pop false element

			if(expression[i] == 'T') stack.push_front(_true);
			else stack.push_front(_false);
		}
		else
			stack.push_front(expression[i]);
	}
	return string(1, stack.front());
}

int main(int argc, char const *argv[])
{
	string expression = "T?2:3";
	cout << parseTernary(expression) << endl;
	return 0;
}