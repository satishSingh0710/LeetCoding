class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res; 
        int m = l.size(); 
        for(int i = 0;i<m;i++){
            int ll = l[i]; 
            int rr = r[i]; 
            if(ll == rr){res.push_back(false); continue;}
            vector<int> temp; 
            for (ll; ll<=rr;ll++){
                temp.push_back(nums[ll]); 
            }
            sort(temp.begin(), temp.end()); 
            int d = temp[1] - temp[0]; 
            bool ap = true; 
            for (int j = 1;j<temp.size();j++){
                if(temp[j] - temp[j-1] != d){
                    res.push_back(false); 
                    ap = false; 
                    break; 
                }
            }
            if(ap){
              res.push_back(true);   
            } 
        }
        return res; 
    }
};