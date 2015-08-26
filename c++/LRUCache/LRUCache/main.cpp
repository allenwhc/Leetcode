/*
*	Last Recently Used (LRU) Cache
*	Last Modified: 7/16/2015
*/

#include <utility>
#include <unordered_map>
#include <iostream>
using namespace std;



class LRUCache{
private:
	class ListNode
	{
	public:
		int val;
		int key;
		ListNode *next;
		ListNode *prev;
		ListNode(int x, int y) :key(x), val(y), next(NULL), prev(NULL){}
	};
	unordered_map<int, ListNode*> hmap;	//Hash map
	int capacity;
	ListNode *head = NULL;
	ListNode *end = NULL;
public:
	LRUCache(int val) {
		capacity = val;
	}

	int get(int key) {
		if (hmap.find(key) != hmap.end()){
			ListNode *node = hmap[key];		//If the given key if found in the map, get the corresponding node
			deleteNode(node);
			setHead(node);
			return node->val;
		}
		else return -1;
	}

	//Delete node from the doubly-linked list
	void deleteNode(ListNode *node){
		if (node->prev) node->prev->next = node->next;
		else head = node->next;

		if (node->next) node->next->prev = node->prev;
		else end = node->prev;
	}

	//Set new head of the list
	void setHead(ListNode *node){
		node->next = head;
		node->prev = NULL;
		if (head) head->prev = node;
		head = node;
		if (!end) end = head;
	}

	void set(int key, int value) {
		//If the node info exists in the map, refresh the value of the node
		//Swap the node from the original place to the head of the list
		if (hmap.find(key) != hmap.end()){
			ListNode *existNode = hmap[key];
			existNode->val = value;
			deleteNode(existNode);
			setHead(existNode);
		}
		//else, create a new node in the list, and update the map as well
		else{
			ListNode *createNode = new ListNode(key, value);
			
			//If the size of hash map exceeds the capacity of the cache,
			//delete key of the end, and add key of the newly created node to hash map
			//Meanwhile, remove the end node from the list, and insert the new node to the list
			if (hmap.size() >= capacity){
				hmap.erase(end->key);
				deleteNode(end);
				setHead(createNode);
			}
			//else, add the newly created node directly to the list
			else setHead(createNode);	
			hmap[key] = createNode;
		}
	}
};

void main(int argc, char* argv[]){
	LRUCache c(2);
	c.set(2, 1);
	c.set(1, 1);
	vector<int> getVal;
	getVal.push_back(c.get(2));
	c.set(4, 1);
	getVal.push_back(c.get(1));
	getVal.push_back(c.get(2));
	for (int g : getVal)
		cout << g << " ";
	cout << endl;
	system("pause");
}