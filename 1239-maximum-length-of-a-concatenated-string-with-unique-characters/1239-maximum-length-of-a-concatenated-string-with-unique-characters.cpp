class Solution {
public:
    int maxxLength  = INT_MIN;
    void solve(vector<string> &arr, int index, string curr, unordered_map<char,int> mp){
       if (index == arr.size()){
          maxxLength = max(maxxLength, (int)curr.size());
          return;
       }
      
       bool cant = false;
       unordered_map<char,int> mp2 = mp;
       for (auto &i: arr[index]){
         mp2[i]++;
         if (mp2[i] == 2){
           cant = true; break;
         }
       }
       if(cant== false){
           solve(arr, index+1, curr + arr[index],mp2);
       }

       solve(arr, index+1, curr,mp);
      
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int> mp;
         solve(arr,0,"",mp);
         return maxxLength;
    }
};