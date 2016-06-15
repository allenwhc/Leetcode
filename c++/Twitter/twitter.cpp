#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <list>
using namespace std;

void printNewsFeed(vector<int> &feed);

class Twitter {
	struct Tweet{
		int userId, tweetId, label;
		Tweet(int x, int y, int z): userId(x), tweetId(y), label(z){}
	};
	struct MyCompare
	{
		bool operator()(pair<list<Tweet>::iterator, list<Tweet>::iterator> t1, pair<list<Tweet>::iterator, list<Tweet>::iterator> t2){
			return t1.first->label < t2.first->label;
		}
	};
	unordered_map<int, list<Tweet>> tweets;
	unordered_map<int, unordered_set<int>> follows;
	int most_recent = 10;
	int label = 0;
	
public:
	/** Initialize your data structure here. */
	Twitter() {
	}
	
	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		follows[userId].insert(userId);
		tweets[userId].push_front(Tweet(userId, tweetId, label));
		label++;
	}
	
	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> feed;
		priority_queue<pair<list<Tweet>::iterator, list<Tweet>::iterator>, vector<pair<list<Tweet>::iterator, list<Tweet>::iterator>>, MyCompare> pq;
		for (auto it = follows[userId].begin(); it != follows[userId].end(); ++it){
			if (tweets[*it].begin() != tweets[*it].end())
				pq.push(make_pair(tweets[*it].begin(), tweets[*it].end()));
		}
		for (int i=0; i<most_recent && !pq.empty(); i++){
			auto top = pq.top();
			pq.pop();
			feed.push_back(top.first->tweetId);
			if (++top.first != top.second)
				pq.push(top);
		}
		return feed;
	}
	
	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		follows[followerId].insert(followerId);
		follows[followerId].insert(followeeId);
	}
	
	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (follows.find(followerId) != follows.end() && followerId != followeeId)
			follows[followerId].erase(followeeId);
	}
};

void printNewsFeed(vector<int> feed){
	for(auto it = feed.begin(); it != feed.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main(int argc, char const *argv[])
{
	Twitter tweet;
	tweet.postTweet(1,5);
	tweet.follow(1,2);
	tweet.follow(2,1);
	printNewsFeed(tweet.getNewsFeed(2));
	tweet.postTweet(2,6);
	printNewsFeed(tweet.getNewsFeed(1));
	printNewsFeed(tweet.getNewsFeed(2));
	tweet.unfollow(2,1);
	printNewsFeed(tweet.getNewsFeed(1));
	printNewsFeed(tweet.getNewsFeed(2));
	tweet.unfollow(1,2);
	printNewsFeed(tweet.getNewsFeed(1));
	printNewsFeed(tweet.getNewsFeed(2));
	return 0;
}