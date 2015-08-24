/*
*	Intersection of Two Linked Lists
*	Last Modified: 7/21/2015
*	Hint:
		1) Get count of the nodes in first list, let count be c1.
		2) Get count of the nodes in second list, let count be c2.
		3) Get the difference of counts d = abs(c1 ¨C c2)
		4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
		5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
*/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		int countA = 0, countB = 0;
		ListNode *pA = headA, *pB = headB;

		//Get count of listA and listB
		while (pA){
			pA = pA->next;
			countA++;
		}
		while (pB){
			pB = pB->next;
			countB++;
		}

		int diffCount = abs(countA - countB);	//Calculate the difference in length
		ListNode *curr1 = countA > countB ? headA : headB;
		ListNode *curr2 = countA > countB ? headB : headA;

		int count = 0;
		//Traverse the bigger list until the node which makes two lists equal in size
		while (curr1->next&&count < diffCount){
			curr1 = curr1->next;
			count++;
		}

		//cout << curr1->val << "," << curr2->val << endl;
		ListNode *intersect = NULL;
		while (curr1 && curr2){
			if (curr1->val == curr2->val){
				return curr1;
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		return NULL;
	}
};

void main(int argc, char *argv[]){
	ListNode *headA = new ListNode(3);
	ListNode *tailA = headA;
	ListNode *printA = headA;
	ListNode *A1 = new ListNode(6);
	tailA->next = A1;
	tailA = tailA->next;
	ListNode *A2 = new ListNode(9);
	tailA->next = A2;
	tailA = tailA->next;
	ListNode *A3 = new ListNode(15);
	tailA->next = A3;
	tailA = tailA->next;
	ListNode *A4 = new ListNode(30);
	tailA->next = A4;
	tailA = tailA->next;

	ListNode *headB = new ListNode(10);
	ListNode *tailB = headB;
	ListNode *printB = headB;
	ListNode *B1 = new ListNode(15);
	tailB->next = B1;
	tailB = tailB->next;
	ListNode *B2 = new ListNode(30);
	tailB->next = B2;
	tailB = tailB->next;

	cout << "The first list is: ";
	while (printA){
		cout << printA->val;
		printA = printA->next;
		if (printA) cout << "->";
	}
	cout << endl;
	cout << "The second list is: ";
	while (printB){
		cout << printB->val;
		printB = printB->next;
		if (printB) cout << "->";
	}
	cout << endl;
	Solution s;
	ListNode *res = s.getIntersectionNode(headA, headB);
	if (res){
		cout << "The intersection node of the above two lists is: ";
		cout << res->val << endl;
	}
	else cout << "No Intersection" << endl;
	
	system("pause");
}