#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

/*
*	Reservior Sampling
*	Time complexity: O(n)
*	Extra space: O()
*/
class Solution{
	ListNode *h;
public:
	Solution(ListNode *head){
		h = head;	//Copy input list to class memeber
	}

	int getRandom(){
		ListNode *curr = h;
		int ret = curr->val;
		for(int i=1; curr != NULL; i++){
			//cout << rand()%(i+1) << endl;
			if(rand()%i < 1) ret = curr->val;
			curr = curr->next;
		}
		return ret;
	}
};

void printList(ListNode *head){
	cout << "Linked list: ";
	while(head){
		cout << head->val;
		head = head->next;
		if(head) cout << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(10);
	ListNode *tail = head, *print = head;
	ListNode *n1 = new ListNode(1);
	tail->next = n1;
	tail = tail->next;
	ListNode *n2 = new ListNode(10);
	tail->next = n2;
	tail = tail->next;
	ListNode *n3 = new ListNode(20);
	tail->next = n3;
	tail = tail->next;
	ListNode *n4 = new ListNode(100);
	tail->next = n4;
	tail = tail->next;
	printList(print);
	Solution sol(head);
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;
	cout << sol.getRandom() << endl;

	return 0;
}
