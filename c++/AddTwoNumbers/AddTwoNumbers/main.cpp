/*
*	Adding Two Numbers
*	Last Modified: 6/5/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	//Adds two numbers from two singly linked lists
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
		int carry = 0;	//Carry bit
		ListNode *result = new ListNode(0);
		ListNode *node1, *node2, *sum;
		node1 = l1;		//Saves head1 to a temporary node
		node2 = l2;		//Saves head2 to a temporary node
		sum = result;	//Save result to a temporary node
		if (node1 == NULL && node2 == NULL)
			return NULL;	//If both of the lists are empty, then returns an empty list
		while (node1 != NULL || node2 != NULL)
		{
			if (node1 != NULL)
			{
				carry = carry + node1->val;
				node1 = node1->next;
			}
			if (node2 != NULL)
			{
				carry = carry + node2->val;
				node2 = node2->next;
			}
			sum->next = new ListNode(carry % 10);	//Creates new nodes in the result list initialized by the quotient of carry/10
			sum = sum->next;
			carry /= 10;	//Clears carry
		}
		if (carry % 10 != 0)
			sum->next = new ListNode(carry % 10);	//If the sum of the last bit is greater than 10, then needs a new carry bit
		return result->next;
	}
};

void main(int argc, char* argv[]){
	//Initialize two singly linked lists
	ListNode *head1 = new ListNode(2);
	ListNode *tail1 = head1;
	ListNode *node1_1 = new ListNode(4);
	tail1->next = node1_1;
	tail1 = tail1->next;
	ListNode *node1_2 = new ListNode(3);
	tail1->next = node1_2;
	tail1 = tail1->next;

	ListNode *head2 = new ListNode(5);
	ListNode *tail2 = head2;
	ListNode *node2_1 = new ListNode(6);
	tail2->next = node2_1;
	tail2 = tail2->next;
	ListNode *node2_2 = new ListNode(7);
	tail2->next = node2_2;
	tail2 = tail2->next;

	//Gets the result
	ListNode *sumResultHead;
	Solution s;
	sumResultHead = s.addTwoNumbers(head1, head2);
	cout << "The first list is: ";
	while (head1 != NULL){
		cout << head1->val;
		if (head1->next != NULL)
			cout << "->";
		head1 = head1->next;
	}
		
	cout << endl << "The second list is: ";
	while (head2 != NULL){
		cout << head2->val;
		if (head2->next != NULL)
			cout << "->";
		head2 = head2->next;
	}

	cout << endl << "The sum of the two lists is: ";
	while (sumResultHead != NULL){
		cout << sumResultHead->val;
		if (sumResultHead->next != NULL)
			cout << "->";
		sumResultHead = sumResultHead->next;
	}
	cout << endl;
	system("pause");
}
