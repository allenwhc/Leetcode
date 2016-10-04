#include <vector>
#include <iostream>
#include <queue>
using namespace std;
/*
*	Heap solution
*	Time complexity: O(mn)
*	Extra space: O(mn)
*/
struct Block
{
	int val;
	int x,y;
	Block():val(0),x(0),y(0){}
	Block(int v, int i, int j):val(v),x(i),y(j){}
};

int trapRainWater(vector<vector<int>>& heightMap){
	if(!heightMap.size() || !heightMap[0].size()) return 0;
	int m = heightMap.size(), n = heightMap[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	auto Compare = [](Block& b1, Block& b2){
		if(b1.val != b2.val) return b1.val > b2.val;
		else return b1.x!=b2.x?b1.x>b2.x:b1.y>b2.y;
	};
	priority_queue<Block, vector<Block>, decltype(Compare)> pq(Compare);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			if(!i || !j || i==m-1 || j==n-1){
				pq.push(Block(heightMap[i][j],i,j));
				visited[i][j] = true;
			}
	}
	vector<pair<int,int>> directions = {{0,-1}, {0,1}, {-1,0}, {1,0}};
	int res = 0;
	while(!pq.empty()){
		int height = pq.top().val, i = pq.top().x, j = pq.top().y;
		pq.pop();
		for(auto &d:directions){
			int x = i + d.first, y = j + d.second;
			if(x>=0 && x<m && y>=0 && y<n && !visited[x][y]){
				if(height > heightMap[x][y]) res += height - heightMap[x][y];
				pq.push(Block(max(heightMap[x][y],height),x,y));
				visited[x][y] = true;
			}
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> heightMap = {{1,4,3,1,3,2},
									 {3,2,1,3,2,4},
									 {2,3,3,2,3,1}
									 };
	cout << "Max trapping rain water: " << trapRainWater(heightMap) << endl;
	return 0;
}