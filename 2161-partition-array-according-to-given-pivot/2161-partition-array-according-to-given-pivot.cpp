class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left,right,mid;
        for (auto &i: nums){
            if (i==pivot){mid.push_back(i);}
            if (i<pivot){left.push_back(i);}
            else if (i>pivot) right.push_back(i);
        }
        nums.clear();
        for (auto &i: left){nums.push_back(i);}
        for (auto &i: mid){nums.push_back(i);}
        for(auto &i: right){nums.push_back(i);}
        return nums;
    }
};