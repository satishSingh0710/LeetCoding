class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        // if There are same color baloons continuosly then we have to make sure that we remove all of them except the one, so we'll not remove the one which require the maximum time to remove, others which require less time, we'll remove them. 
        
        // maxCost will store the max cost of the removal, and currCost will keep the sum of all the cost if the baloons are of same color, 
        
        // the moment we find that two consecutive baloons are not of same color then we'll remove the maxCost from the currCost and set the max cost to 0 because we'll be iterating the next set of baloons afterwards, the we'll repeat the process again and again. 
        
        // T.C ->  O(n);
        // S.C -> O(1);
        int n = colors.size(), maxCost = time[0], currCost = time[0];
        
        for (int i =  1; i<n;i++){
            if (colors[i]!= colors[i-1]){
                currCost-= maxCost;
                maxCost = 0;
            }
            currCost+= time[i];
            maxCost = max(maxCost, time[i]);
        }
        
        return currCost - maxCost;
    }
};

/*
This was my previous solution I was able to run 109 cases out of 113
but this approach is not the most efficient, Definitely it is not most efficient approach. God knows when I'll able to come up with the best ideas out there. 
*/

// class Solution {
// public:
//     int minCost(string colors, vector<int>& time) {
//         int n = colors.size(),cost = 0, diff = 1;
//         for (int i = 0; i< n-1 ;i++){
//             if (diff>=n-1) return cost;
//             if (colors[i] == colors[i+diff]){
//                 cout<<"choosing between "<<time[i]<<" and "<<time[i+diff]<<endl;
//                 if (time[i]>=0 && time[i+diff]>=0){
//                     if(time[i]<time[i+diff]){
//                         cost+= time[i]; time[i] = -1; diff = 1;
//                     }
//                     else{
//                         cost+= time[i+diff]; time[i+diff] = -1;
//                         diff++;i--;
//                     }
//                 }
//             }else if (diff>1){
//                 diff = 1;i--;
//             }
//         }
        
//         return cost;
//     }
// };