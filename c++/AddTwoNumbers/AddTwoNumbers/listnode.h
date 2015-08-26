#include <iostream>
using namespace std;

//Definition for singly-linked list
struct Listnode{
	int val;	//value of the node
	Listnode *next;	//pointer to the next node
};

//Linked list
class linkedList{
public:
	//Constructor
	linkedList(){
		head = NULL;
		tail = NULL;
	}

	//Adds a new node to the front of the current node
	void addFirst(Listnode *newNode){
		if (newNode == NULL)
			return;
		else{

		}
	}

	//Adds a new node to the back of the current node
	void addLast(Listnode *newNode){

	}
private:
	Listnode *head;
	Listnode *tail;
};