class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto &i: gifts){
            pq.push(i);
        }
        
        for (int i = 0;i<k;i++){
           int top  = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        long long int res = 0;
        while(pq.size()){
            res += pq.top();
            pq.pop();
        }
        
        return res;
        
    }
};