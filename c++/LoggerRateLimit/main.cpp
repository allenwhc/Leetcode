#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Logger {
	unordered_map<string, int> mp;
public:
	/** Initialize your data structure here. */
	Logger() {
		
	}
	
	/** Returns true if the message should be printed in the given timestamp, otherwise returns false. The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		bool canPrint = false;
		if (mp.find(message) == mp.end()){
			mp[message] = timestamp;
			canPrint = true;
		}
		else{
			if (timestamp - mp[message] >= 10){
				mp[message] = timestamp;
				canPrint = true;
			}
			else canPrint = false;
		}
		return canPrint;
	}
};

int main(int argc, char const *argv[])
{
	Logger log;
	cout << log.shouldPrintMessage(1, "foo") << endl;
	cout << log.shouldPrintMessage(2, "bar") << endl;
	cout << log.shouldPrintMessage(3, "foo") << endl;
	cout << log.shouldPrintMessage(8, "bar") << endl;
	cout << log.shouldPrintMessage(10, "foo") << endl;
	cout << log.shouldPrintMessage(11, "foo") << endl;
	return 0;
}