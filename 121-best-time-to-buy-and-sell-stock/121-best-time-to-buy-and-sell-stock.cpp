class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = INT_MAX, max_profit = 0;
        for (auto &price: prices){
            int curr_profit = price - curr_min; 
            max_profit = max(max_profit, curr_profit);
            curr_min = min(curr_min, price);
        } return max_profit;
    }
};