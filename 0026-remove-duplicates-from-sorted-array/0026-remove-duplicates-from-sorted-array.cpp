 class Solution {
 public:
     int removeDuplicates(vector<int>& nums) {
//         int size = nums.size();
//         if (size == 1)
//             return 1;
//         int count=0;
//         for (int i=0;i<nums.size()-count-1;i++)
//         {
// //             if (nums[i]==nums[i+1])
// //             {
// //                 int store = nums[i];
// //                 nums.erase(nums.begin()+i);
// //                 nums.push_back(store);
              
// //                 count = count+1;
// //             }
            
//             if (nums[i]==nums[i+1])
//             {
//              int store = nums[i];
//                 nums.erase(nums.begin()+i);
//                 nums.push_back(store);
              
//                 count = count+1;
//                  i = i-1;
//             }
//         }
        
//         return nums.size()-count;
         
         int count = 0;
for(int i = 1; i < nums.size(); i++){
    if(nums[i] == nums[i-1]) count++;
    else nums[i-count] = nums[i];
}
return nums.size()-count;
   }
 };

