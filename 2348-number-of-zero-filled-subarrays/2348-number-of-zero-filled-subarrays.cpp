class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int> temp;
        long long int ans = 0;
        for (int i = 0;i<nums.size();i++){
            // cout<<i<<" ";
            if (nums[i] == 0){
                // cout<<"done"<<endl;
                int count = 0;
                for (int j = i;j<nums.size();j++){
                     i = j;
                    if (nums[j] != 0){
                        break;
                    }
                    count++;
                }
                temp.push_back(count);
            }
        }
        
        for (auto &i: temp){
            // cout<<i<<endl;
            // ans += (long long int)(i/2)*(i+1);
            if (i%2 ==0){
                ans += (long long int)(i/2) * (i+1);
            }else{
                ans += (long long int)(i)*((i+1)/2);
            }
        }
        return ans;
    }
};