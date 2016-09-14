#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int maxRotateFunction(vector<int>& A){
	if(A.empty()) return 0;
	//i=0
	int currSum = 0, n = A.size();
	int elementSum = 0;
	for(int i=0; i<n; i++){
		elementSum += A[i];
		currSum += i * A[i];
	}
	int maxSum = currSum;
	for(int i=1; i<n; i++){
		int diff = elementSum - n * A[n-i];
		currSum += diff;
		if(currSum > maxSum) maxSum = currSum;
	}
	return maxSum;
}

int main(int argc, char const *argv[])
{
	vector<int> A = {4,3,2,6};
	cout << maxRotateFunction(A) << endl;
	return 0;
}