#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

class PhoneDirectory{
	int limit;
	queue<int> available;
	unordered_set<int> used;
public:
	PhoneDirectory(int maxNumbers):limit(maxNumbers){
		for(int i=0; i<maxNumbers; i++)
			available.push(i);
	}

	 /** Provide a number which is not assigned to anyone.
		@return - Return an available number. Return -1 if none is available. */
	int get() {
		if(available.empty()) return -1;
		int num = available.front();
		available.pop();
		used.insert(num);
		return num;
	}
	
	/** Check if a number is available or not. */
	bool check(int number) {
		if(number>=limit || number<0) return false;
		return used.find(number) == used.end();
	}
	
	/** Recycle or release a number. */
	void release(int number) {
		if(used.find(number) != used.end()){
			used.erase(number);
			available.push(number);
		}
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}