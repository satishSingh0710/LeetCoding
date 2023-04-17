class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = floor( arr.size()/4);
        int count = 0;
        int prev = arr[0];
        for (int i = 0;i<arr.size();i++){
            if (arr[i] == prev) count++; 
            if (count > size) return arr[i];
            if (arr[i] != prev){
                prev = arr[i]; 
                count=1;
            }
        }
        return -1;
    }
};