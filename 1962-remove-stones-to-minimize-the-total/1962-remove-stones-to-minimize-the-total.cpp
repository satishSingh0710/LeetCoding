class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int total = 0;
        for (auto &i: piles){
            q.push(i); total+= i;
        }
        
        
        while(k--){
            int weight = q.top(); q.pop();
            total-=weight; weight-= floor(weight/2);
            total+= weight; q.push(weight);
        }
        
        return total;
    }
};