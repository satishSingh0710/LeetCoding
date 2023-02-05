//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int wt[], int val[], int n, int W, int index, vector<vector<int>> &dp){
        if (index == n){
            return 0;
        }
        if (dp[W][index] != -1){
            return dp[W][index];
        }
        int pick = 0, notPick = 0;
        if (wt[index]<= W){
            pick =  val[index] + solve(wt, val, n, W - wt[index], index+1, dp);
        }
        notPick = solve(wt, val, n, W, index + 1, dp);
        return dp[W][index] =  max(pick, notPick);
        
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(W+1, vector<int>(n, -1));
       return solve(wt, val, n, W, 0, dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends