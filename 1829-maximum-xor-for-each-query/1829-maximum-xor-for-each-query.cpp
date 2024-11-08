class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit){
        
        vector<int> res,xors; 
        int curXor = nums[0]; 
        xors.push_back(curXor); 
        
        for (int i = 1;i<nums.size();i++){
            curXor ^= nums[i]; 
            xors.push_back(curXor); 
        }
        
        
        for (int i = xors.size()-1;i>=0;i--){
            int num = 0; 
            int currXor = xors[i]; 

            for (int j = 0;j<maximumBit;j++){
                int bit = ((currXor>>j) & 1);
                
                if(bit == 0){
                    int one = 1; 
                    num |= (one<<j);  
                }
            }
            
            res.push_back(num); 
        }
        
        return res; 
    }
};