class Solution {
public:
    int minPartitions(string n) {
        int res = INT_MIN;
        for (auto &i: n){
            res = max(res, i -'0');
        } return res;
    }
};