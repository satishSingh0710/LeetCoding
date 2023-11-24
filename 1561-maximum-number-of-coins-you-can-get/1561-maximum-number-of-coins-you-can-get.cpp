class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int i = 0, j = piles.size()-1;
        int res = 0; 
        sort(piles.begin(), piles.end()); 
        while(j-i+1 >= 3){
            res += piles[j-1];
            i++; 
            j-=2;
        }
        return res; 
    }
};