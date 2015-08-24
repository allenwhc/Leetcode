/*
*	Clone Graph
*	Last Modified: 7/22/2015
*/

#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hmap;
		queue<UndirectedGraphNode*> q;

		//Initialize the queue and the map
		UndirectedGraphNode *newHead = new UndirectedGraphNode(node->label);
		q.push(node);
		hmap[node] = newHead;

		while (!q.empty()){
			UndirectedGraphNode *curr = q.front();
			q.pop();
			vector<UndirectedGraphNode*> currNeighbors = curr->neighbors;
			for (UndirectedGraphNode *n : currNeighbors){
				if (hmap.find(n) == hmap.end()){
					UndirectedGraphNode *cloneNeighbors = new UndirectedGraphNode(n->label);
					hmap[n] = cloneNeighbors;
					hmap[curr]->neighbors.push_back(cloneNeighbors);
					q.push(n);
				}
				else hmap[curr]->neighbors.push_back(hmap[n]);
			}
		}
		return newHead;
	}
};

void main(int argc, char *argv[]){
	Solution s;
	UndirectedGraphNode *vertex1 = new UndirectedGraphNode(0);
	UndirectedGraphNode *vertex2 = new UndirectedGraphNode(1);
	UndirectedGraphNode *vertex3 = new UndirectedGraphNode(2);
	vertex1->neighbors = { vertex2, vertex3 }; 
	vertex2->neighbors = { vertex1, vertex3 };
	vertex3->neighbors = { vertex1, vertex2, vertex3 };

	vector<UndirectedGraphNode*> vertices;
	vertices.push_back(vertex1);
	vertices.push_back(vertex2);
	vertices.push_back(vertex3);
	cout << "The original graph is: " << endl;
	for (int i = 0; i < vertices.size(); i++){
		cout << "Current node: " << vertices[i]->label << ", ";
		cout << "neighbors: ";
		for (int j = 0; j < vertices[i]->neighbors.size(); j++)
			cout << vertices[i]->neighbors[j]->label << " ";
		cout << endl;
	}
	UndirectedGraphNode *result1 = s.cloneGraph(vertex1);
	cout << "The clone gragh is: " << endl;
	cout << "Current node: " << result1->label << ", ";
	cout << "neighbors: ";
	for (UndirectedGraphNode* neighbor:result1->neighbors)
		cout << neighbor->label << " ";

	UndirectedGraphNode *result2 = s.cloneGraph(vertex2);
	cout << endl << "Current node: " << result2->label << ", ";
	cout << "neighbors: ";
	for (int i = 0; i < result2->neighbors.size(); i++)
		cout << result2->neighbors[i]->label << " ";

	UndirectedGraphNode *result3 = s.cloneGraph(vertex3);
	cout << endl << "Current node: " << result3->label << ", ";
	cout << "neighbors: ";
	for (int i = 0; i < result3->neighbors.size(); i++)
		cout << result3->neighbors[i]->label << " ";
	cout << endl;
	system("pause");
}