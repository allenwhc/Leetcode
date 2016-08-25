#include <iostream>
using namespace std;

class PhoneDirectory{
	int numbers;
public:
	PhoneDirectory(int maxNumbers):numbers(maxNumbers){

	}

	int get(){
		
	}

	bool check(int number){
		if(number >= numbers) return false;
	}

	void release(int number){

	}
};

int main(int argc, char const *argv[])
{
	/* code */
	int maxNumbers = 3;
	PhoneDirectory pd(maxNumbers);
	cout << pd.get() << endl;
	cout << pd.get() << endl;
	cout << pd.check(2) << endl;
	cout << pd.get() << endl;
	cout << pd.check(2) << endl;
	pd.release(2);
	cout << pd.check(2) << endl;
 	return 0;
}