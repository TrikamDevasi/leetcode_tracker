// Last updated: 30/07/2026, 10:21:28
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> friendSet(friends.begin(), friends.end());
        vector<int> result;
        
        for (int id : order) {
            if (friendSet.count(id)) {
                result.push_back(id);
            }
        }
        return result;
    }
};
