class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp1; vector<int> temp2;
        for (auto &i: nums){if (i<0) temp1.push_back(i);
         else{temp2.push_back(i);}                   
        }
        nums.clear();
        int i = 0, j = 0;
        int n = temp1.size();
        while(i<n){
            nums.push_back(temp2[i]); 
            nums.push_back(temp1[i]);
            i++;
        }
        
        return nums;
    }
};