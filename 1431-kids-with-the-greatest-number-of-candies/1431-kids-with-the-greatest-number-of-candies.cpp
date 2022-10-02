class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(),candies.end());
        vector<bool> res;
        for (auto &i: candies){
            if (i+extraCandies >= maxi){res.push_back(true);}
            else res.push_back(false);
        }
        return res;
    }
};