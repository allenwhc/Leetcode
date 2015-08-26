/*
*	Implement Stack using Queues
*	Last Modified: 7/24/2015
*/

#include <queue>
#include <iostream>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		//1. Enqueue x into q2
		//2. Save all elements in q1 to q2, clear q1
		//3. Swap names for q1 and q2
		q2.push(x);
		while (!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}

	// Removes the element on top of the stack.
	void pop() {
		if (q1.size() > 0) q1.pop();
		else if (q2.size() > 0) q2.pop();
	}

	// Get the top element.
	int top() {
		if (q1.size() > 0) return q1.front();
		else if (q2.size() > 0) return q2.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q2.empty() && q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

void main(int argc, char *argv[]){

}