class Solution {
public:
    int area = INT_MIN;
    int largestPerimeter(vector<int>& t) {
     sort(t.begin(),t.end());
     int n = t.size();
     for (int i  = n-1;i>=2;i--){
         if (t[i-1] + t[i-2]<=t[i]) continue;
         else return t[i]+t[i-1]+t[i-2];
     }
        
        return 0;
    }
};