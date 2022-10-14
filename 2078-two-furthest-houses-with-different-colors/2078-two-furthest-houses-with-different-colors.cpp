class Solution {
public:
    int maxDistance(vector<int>& c) {
        int maxDist = INT_MIN;
        int n = c.size(); 
            for(int i = 0;i<n-1;i++){
            for (int j = i+1;j<n;j++){
                if (c[i]!=c[j]){
                    maxDist = max(maxDist, j - i );
                }
            }
        }
        
        return maxDist;
    }
};