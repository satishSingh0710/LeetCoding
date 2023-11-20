class Solution {
public:
    int cost(vector<string> &garbage,vector<int> &travel, vector<int> &temp, char type){
        int currIdx = 0; 
        int total = 0; 
        for (int i = 0;i<temp.size();i++){
            while(currIdx != temp[i]){
                total += travel[currIdx]; 
                currIdx++; 
            }
    
            for (auto &j: garbage[currIdx]){
                if(j == type){total++;}
            }
        }
        return total;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> gIdx, pIdx, mIdx; 
        for(int i = 0;i<garbage.size();i++){
            string str = garbage[i]; 
            bool g = false, p  = false, m = false; 
            for (auto &j: str){
                if(j == 'M'){m = true;}
                if(j == 'G'){g = true;}
                if(j == 'P'){p = true;}
            }
            if(m){mIdx.push_back(i);}
            if(p){pIdx.push_back(i);}
            if(g){gIdx.push_back(i);}
        }
        int finalCost = 0; 
        finalCost += cost(garbage, travel,gIdx,'G'); 
        finalCost += cost(garbage,travel,pIdx,'P');
        finalCost += cost(garbage,travel,mIdx,'M');
        
        return finalCost; 
        
    }
};