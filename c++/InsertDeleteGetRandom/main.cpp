#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <stdlib.h>
using namespace std;

class RandomizedSet {
	vector<int> randomSet;
	map<int,int> mp;
public:
	/** Initialize your data structure here. */
	RandomizedSet() {}
	
	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if(mp.find(val) != mp.end()) return false;
		randomSet.push_back(val);
		mp[val] = find(randomSet.begin(), randomSet.end(), val) - randomSet.begin();	//Val -> index
		return true;
	}
	
	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if(mp.find(val) == mp.end()) return false;
		if(randomSet.empty()) return false;
		auto it = find(randomSet.begin(), randomSet.end(), val);
		randomSet.erase(it);
		mp.erase(mp.find(val));
		return true;
	}
	
	/** Get a random element from the set. */
	int getRandom() {
		auto it = mp.begin();
		advance(it, rand()%mp.size());
		return randomSet[it->second];
	}

	void print(){
		cout << "current set: ";
		for(auto x: randomSet) cout << x << " ";
		cout << endl;
	}

};

class RandomizedCollection {
	map<int, vector<int>> mp;
	vector<int> collection;
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {}
	
	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		collection.push_back(val);
		mp[val].push_back(collection.size()-1);
		return mp[val].size() == 1;
	}
	
	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if(collection.empty()) return false;
		if(mp.find(val) == mp.end() || mp[val].size() == 0) return false;
		int last_element = collection.back();
		if(last_element != val){
			collection[mp[val].back()] = last_element;
			mp[last_element].back() = mp[val].back();
		}
		mp[val].pop_back();
		collection.pop_back();
		return true;
	}
	
	/** Get a random element from the collection. */
	int getRandom() {
		return collection[rand()%collection.size()];
	}

	void print(){
		cout << "current collection: ";
		for(auto &v: collection) cout << v << " ";
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	RandomizedSet randomSet;
	cout << randomSet.insert(1) << endl;
	randomSet.print();
	cout << randomSet.remove(2) << endl;
	randomSet.print();
	cout << randomSet.insert(2) << endl;
	randomSet.print();
	cout << randomSet.getRandom() << endl;
	randomSet.print();
	cout << randomSet.remove(1) << endl;
	randomSet.print();
	cout << randomSet.insert(2) << endl;
	randomSet.print();
	cout << randomSet.getRandom() << endl;
	randomSet.print();

	RandomizedCollection collection;
	cout << collection.insert(10) << endl;
	collection.print();
	cout << collection.insert(10) << endl;
	collection.print();
	cout << collection.insert(20) << endl;
	collection.print();
	cout << collection.insert(20) << endl;
	collection.print();
	cout << collection.insert(30) << endl;
	collection.print();
	cout << collection.insert(30) << endl;
	collection.print();
	cout << collection.remove(10) << endl;
	collection.print();
	cout << collection.remove(10) << endl;
	collection.print();
	cout << collection.remove(30) << endl;
	collection.print();
	cout << collection.remove(30) << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	cout << collection.getRandom() << endl;
	collection.print();
	return 0;
}