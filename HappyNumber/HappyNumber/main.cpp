#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool isHappy(int n){
		bool happy = false;
		int currentSum = n;
		vector<int> digits;
		if (n == 1)
		{
			happy = true;
		}
		else
		{
			while (currentSum != 1)
			{
				digits.clear();
				
				while (currentSum != 0)
				{
					digits.push_back(currentSum % 10);	//store digits to an array
					currentSum = currentSum / 10;
				}
				currentSum = sumOfSquare(digits);
				if (currentSum == 4 || 
					currentSum == 16 || 
					currentSum == 37 || 
					currentSum == 58 ||
					currentSum == 89 ||
					currentSum == 145 ||
					currentSum == 42 ||
					currentSum == 20)
				{
					happy = false;
					break;
				}
				happy = true;
			}
		}
		return happy;
	}
private:
	int sumOfSquare(vector<int> m)
	{
		int sum = 0;
		for (int i = 0; i < m.size(); i++)
		{
			sum = sum + m[i]*m[i];
		}
		return sum;
	}
};

void main(int argc, char*argv[])
{
	int n;
	Solution s;
	bool happyNum;
	cout << "Input a positive integer: ";
	cin >> n;
	if (n <= 0 || n > INT_MAX) cout << "Invalid input!";
	happyNum = s.isHappy(n);
	if (happyNum)
	{
		cout << n << " is a happy number." << endl;
	}
	else
	{
		cout << n << " is not a happy number." << endl;
	}
	system("pause");
}