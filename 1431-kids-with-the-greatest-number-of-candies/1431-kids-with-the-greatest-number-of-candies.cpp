class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxxCandies = INT_MIN;
        vector<bool> res;
        for (auto &i: candies){
            maxxCandies = max(maxxCandies, i);
        }
        for(int i = 0;i<candies.size();i++){
            if (candies[i] + extraCandies >= maxxCandies){
                res.push_back(true); 
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};