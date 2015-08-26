/*
*	Rectangle Area
*	Last Modified: 7/8/2015
*/

#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
		//If no overlap between two rectangles
		if (H < B || F > D) return (area(A, B, C, D) + area(E, F, G, H));
		if (E > C || G < A) return (area(A, B, C, D) + area(E, F, G, H));
		
		//Pick vertices for the overlapped rectangle
		int top = min(H, D);
		int down = max(B, F);
		int right = min(C, G);
		int left = max(A, E);

		return (area(A, B, C, D) + area(E, F, G, H) - area(left, down, right, top));

	}
	int area(int x1, int y1, int x2, int y2){
		return (x2 - x1)*(y2 - y1);
	}
};

void main(int argc, char *argv[]){
	int A = -2, B = 2, C = 2, D = 2, E = 3, F = 3, G = 4, H = 4;
	Solution s;
	cout << "The position of two rectangles is: (" << A << "," << B << "), (" << C << "," << D << ") and (" << E << "," << F << "), (" << G << "," << H << ")"<<endl;
	cout << "The total area covered by the two rectilinear rectangles is: " << s.computeArea(A, B, C, D, E, F, G, H) << endl;
	system("pause");
}