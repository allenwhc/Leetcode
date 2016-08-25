#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element
{
	int val, row, col;
	Element():val(0),row(-1),col(-1){}
	Element(int v, int r, int c):val(v),row(r),col(c){}
};

struct Compare{
	bool operator()(Element &e1, Element &e2){
		return e1.val > e2.val;
	}
};

int kthSmallest(vector<vector<int>> &matrix, int k){
	if(!k || matrix.size() == 0) return 0;
	if(matrix[0].size() == 0) return 0;
	int m = matrix.size(), n = matrix[0].size();
	priority_queue<Element, vector<Element>, Compare> pq;
	for(int j=0; j<n; j++){
		pq.push(Element(matrix[0][j], 0, j));
	}
	while(--k){
		Element e = pq.top();
		pq.pop();
		int curr_row = e.row, curr_col = e.col;
		if(curr_row < m-1) pq.push(Element(matrix[curr_row + 1][curr_col], curr_row + 1, curr_col));
	}
	return pq.top().val;
}

int main(int argc, char const *argv[])
{
	/* code */
	vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	int k = 8;

	cout << k << "th smallest number is: " << kthSmallest(matrix, k) << endl;
	return 0;
}