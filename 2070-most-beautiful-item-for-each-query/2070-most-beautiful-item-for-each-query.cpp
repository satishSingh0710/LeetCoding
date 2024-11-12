class Solution {
public:
    int findIdx(vector<vector<int>> &items, int price){
        int l = 0, r = items.size()-1; 
        int last = 0; 
        while(l <= r){
            int mid = l + (r - l)/2; 
            last = mid; 
            int curPrice = items[mid][0]; 
            if(curPrice > price){
                r = mid - 1; 
            }else{
                l = mid + 1; 
            }
        }
        
        return last; 
        
    }
    static bool comp(const vector<int> &a, const vector<int> &b){
         return a[0] < b[0]; 
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res;
        sort(items.begin(), items.end(), comp); 
        vector<int> maxxSofar; 
        int maxxi = INT_MIN; 
        
        for (auto &i: items){
            // cout<<i[0]<<endl;
            maxxi = max(maxxi, i[1]); 
            maxxSofar.push_back(maxxi); 
        }
        
        for (auto &i: queries){
            int price = i; 
            int idx = findIdx(items, price); 
            if(idx < 0){
                res.push_back(0); 
                continue; 
            }
            if(items[idx][0] > price){
                idx--; 
            }
            if(idx < 0){
                res.push_back(0); 
                continue; 
            }
            
            res.push_back(maxxSofar[idx]);
           
        }
        
        return res; 
    }
};