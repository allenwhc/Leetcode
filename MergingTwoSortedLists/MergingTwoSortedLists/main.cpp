/*
*	Merge Two Sorted Lists
*	Last Modified: 6/24/2015
*/

#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
		if (l1 == NULL && l2 == NULL) return NULL;
		if (l1 != NULL && l2 == NULL) return l1;
		if (l1 == NULL && l2 != NULL) return l2;
		
		ListNode *temp, *head, *l1next, *l2next;
		if (l1->val < l2->val){
			temp = l1;
			l1 = l1->next;
		}
		else{
			temp = l2;
			l2 = l2->next;
		}
		head = temp;
		while (l1 != NULL && l2 != NULL){
			if (l1->val < l2->val){
				l1next = l1->next;
				temp->next = l1;
				temp = l1;
				l1 = l1next;
			}
			else{
				l2next = l2->next;
				temp->next = l2;
				temp = l2;
				l2 = l2next;
			}
		}
		if (l1 == NULL) temp->next = l2;
		if (l2 == NULL) temp->next = l1;
		return head;
	}
};

void main(int argc, char *argv[]){
	ListNode *l10 = new ListNode(1);
	ListNode *l1rintl1 = l10;
	ListNode *taill1 = l10;
	ListNode *l11 = new ListNode(4);
	taill1->next = l11;
	taill1 = taill1->next;
	ListNode *l12 = new ListNode(5);
	taill1->next = l12;
	taill1 = taill1->next;
	ListNode *l13 = new ListNode(10);
	taill1->next = l13;
	taill1 = taill1->next;

	ListNode *l20 = new ListNode(2);
	ListNode *l1rintl2 = l20;
	ListNode *taill2 = l20;
	ListNode *l21 = new ListNode(6);
	taill2->next = l21;
	taill2 = taill2->next;
	ListNode *l22 = new ListNode(7);
	taill2->next = l22;
	taill2 = taill2->next;
	ListNode *l23 = new ListNode(9);
	taill2->next = l23;
	taill2 = taill2->next;

	cout << "The first list is: ";
	while (l1rintl1 != NULL){
		cout << l1rintl1->val;
		l1rintl1 = l1rintl1->next;
		if (l1rintl1 != NULL) cout << "->";
	}
	cout << endl << "The second list is: ";
	while (l1rintl2 != NULL){
		cout << l1rintl2->val;
		l1rintl2 = l1rintl2->next;
		if (l1rintl2 != NULL) cout << "->";
	}

	Solution s;
	ListNode *merge = s.mergeTwoLists(l10, l20);
	cout << endl << "The merged list is: ";
	while (merge != NULL){
		cout << merge->val;
		merge = merge->next;
		if (merge != NULL) cout << "->";
	}
	cout << endl;
	system("l1ause");
}