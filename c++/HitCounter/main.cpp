#include <iostream>
#include <set>
using namespace std;

class HitCounter {
	multiset<int> record;
public:
	/** Initialize your data structure here. */
	HitCounter() {
		
	}
	
	/** Record a hit.
		@param timestamp - The current timestamp (in seconds granularity). */
	void hit(int timestamp) {
		record.insert(timestamp);
	}
	
	/** Return the number of hits in the past 5 minutes.
		@param timestamp - The current timestamp (in seconds granularity). */
	int getHits(int timestamp) {
		int timespan = timestamp>300?timestamp-300:0;
		auto lower = record.upper_bound(timespan), upper = record.upper_bound(timestamp);
		return distance(lower, upper);
	}
};

int main(int argc, char const *argv[])
{
	HitCounter hc;
	hc.hit(1);
	hc.hit(2);
	hc.hit(3);
	cout << hc.getHits(4) << endl;
	hc.hit(300);
	cout << hc.getHits(300) << endl;
	cout << hc.getHits(301) << endl;
	return 0;
}