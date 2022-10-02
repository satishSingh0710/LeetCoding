class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> q;
       int res;
        for (auto &i: nums){q.push(i);}
        while(k--){res = q.top(); q.pop();}
        return res;
    }
};