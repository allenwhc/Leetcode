/*
*	Implement Queue using Stacks
*	Last Modified: 7/7/2015
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue{
public:
	//Push element to the back of queue
	void push(int x){
		if (stack2.empty())
			stack2.push(x);	//If the stack is empty, push element into the stack
		else{
			//If the stack is not empty,
			//First, save the rest elements into another stack, and then clear the stack
			//Then, push the wanted element into the stack
			//At last, push all the other elements back to the stack
			while (!stack2.empty()){
				stack1.push(stack2.top());
				stack2.pop();
			}
			stack2.push(x);
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}

	//Removes the element from in front of queue
	void pop(void){
		stack2.pop();
	}

	//Get the front element
	int peek(void){
		return stack2.top();
	}

	//Return whether the queue is empty
	bool empty(void){
		return stack2.empty();
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

void main(int argc, char* argv[]){
	Queue q;
	q.push(1);
	q.push(2);
	cout << q.peek() << endl;
	system("pause");
}