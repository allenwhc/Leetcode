/*
*	Min Stack
*	Last Modified: 7/26/2015
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
	void push(int x) {
		actualStack.push(x);
		if (x <= getMin())
			minStack.push(x);
		else
			minStack.push(getMin());
	}

	void pop() {
		if (actualStack.top() == getMin()) minStack.pop();
		actualStack.pop();
	}

	int top() {
		return actualStack.top();
	}

	int getMin() {
		if (minStack.empty()) return INT_MAX;
		return minStack.top();
	}
private:
	stack<int> actualStack;	//Actual stack
	stack<int> minStack;	//Auxiliary stack
};

void main(int argc, char* argv[]){
	MinStack stk;
	stk.push(2147483646);
	stk.push(2147483646);
	stk.push(2147483647);
	cout << "top=" << stk.top() << endl;
	stk.pop();
	cout << "minimum=" << stk.getMin() << endl;
	stk.pop();
	cout << "minimum=" << stk.getMin() << endl;
	stk.pop();
	stk.push(2147483647);
	cout << "top=" << stk.top() << endl;
	cout << "minimum=" << stk.getMin() << endl;
	stk.push(INT_MIN);
	cout << "top=" << stk.top() << endl;
	cout << "minimum=" << stk.getMin() << endl;
	stk.pop();
	cout << "minimum=" << stk.getMin() << endl;
	system("pause");
}