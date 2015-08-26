/*
*	Copy List with Random Pointer
*	Last Modified: 7/22/2015
*	Hint: 
		1. Traverse the original linked list and make a copy in terms of data.
		2. Make a hash map of key value pair with original linked list node and copied linked list node.
		3. Traverse the original linked list again and using the hash map adjust the next and random reference of cloned linked list nodes.
*/

#include <unordered_map>
#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		unordered_map<RandomListNode*, RandomListNode*> hmap;	//Create a hash map for mapping the cloned list to original list
		RandomListNode *orgCurr = head;
		RandomListNode *cloneCurr = NULL;
		
		if (!head) return NULL;
		//Traverse the original list and make a copy in terms of data.
		//And map the original list to the clone list
		while (orgCurr){
			cloneCurr = new RandomListNode(orgCurr->label);
			hmap[orgCurr] = cloneCurr;	
			orgCurr = orgCurr->next;
		}

		//Traverse the original list again
		orgCurr = head;
		while (orgCurr){
			cloneCurr = hmap[orgCurr];
			cloneCurr->next = hmap[orgCurr->next];
			cloneCurr->random = hmap[orgCurr->random];
			orgCurr = orgCurr->next;
		}

		return hmap[head];
	}
};

void main(int argc, char *argv[]){
	RandomListNode *head = new RandomListNode(1);
	RandomListNode *tail = head;
	RandomListNode *print = head;
	RandomListNode *n1 = new RandomListNode(2);
	tail->next = n1;
	tail = tail->next;
	RandomListNode *n2 = new RandomListNode(3);
	tail->next = n2;
	tail = tail->next;
	RandomListNode *n3 = new RandomListNode(4);
	tail->next = n3;
	tail = tail->next;
	RandomListNode *n4 = new RandomListNode(5);
	tail->next = n4;
	tail = tail->next;
	head->random = n2;
	n1->random = head;
	n2->random = n4;
	n3->random = n2;
	n4->random = n1;

	cout << "The linked list is: " << endl;
	while (print){
		cout << "The current node is: " << print->label << endl;
		if (print->next) cout << "Next node: " << print->next->label << ", ";
		else cout << "Next node: NULL " << ", ";
		if (print->random) cout << "Random node: " << print->random->label << endl;
		else cout << "Random node:  NULL " << endl;
		print = print->next;
	}

	Solution s;
	RandomListNode *copyList = s.copyRandomList(head);
	cout << endl;
	cout << "The copied list is: " << endl;
	while (copyList){
		cout << "The current node is: " << copyList->label << endl;
		if (copyList->next) cout << "Next node: " << copyList->next->label << ", ";
		else cout << "Next node: NULL " << ", ";
		if (copyList->random) cout << "Random node: " << copyList->random->label << endl;
		else cout << "Random node: NULL " << endl;
		copyList = copyList->next;
	}
	cout << endl;
	system("pause");
}