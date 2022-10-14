class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> q;
        double sum = 0,halfSum;
        int operations = 0;
        for (auto &i: nums){q.push(i); sum+= i;}
        halfSum = sum/2; 
        while(sum>halfSum){
            double val = q.top(); sum -= val;
            q.pop();
            val = val/2; sum+= val; q.push(val); operations++;
        }
        return operations; 
    }
};