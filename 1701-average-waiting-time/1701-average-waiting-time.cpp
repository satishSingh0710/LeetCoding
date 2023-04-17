class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = customers[0][0]; 
        double waitingTime = 0;
        for (auto &i: customers){
            double localWait = 0;
            if (i[0] < currTime){
                localWait = (currTime - i[0]);
            }else{
                currTime = i[0];
            }                          
            localWait += i[1];
            waitingTime += localWait;
            currTime += (i[1]);
        }
        
        return (double)(waitingTime)/(customers.size());
        
    }
};