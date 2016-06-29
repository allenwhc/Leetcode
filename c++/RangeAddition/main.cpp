#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(auto &u : updates){
            int startIndex = u[0], endIndex = u[1], increment = u[2];
            res[startIndex] += increment;
            if(endIndex < length - 1) res[endIndex+1] -= increment;
        }
        for(int i=1; i<length; i++) res[i] += res[i-1];
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2,-2}};
    int length = 5;
    Solution s;
    for(auto &v: s.getModifiedArray(length, updates)) cout << v << " ";
    return 0;
}