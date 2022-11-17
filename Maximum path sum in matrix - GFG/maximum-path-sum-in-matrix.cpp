//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private: 
    int n;
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp,int row, int col){
       if (row == n && (col>=0 && col<=n)) return matrix[row][col];
       if (row<0 || row>n || col<0||col>n) return INT_MIN;
       if(dp[row][col] != -1) return dp[row][col];
       int down, leftDown,rightDown;
       down = matrix[row][col] + solve(matrix, dp, row+1, col);
       leftDown = matrix[row][col] + solve(matrix, dp, row+1, col-1);
       rightDown = matrix[row][col] + solve(matrix, dp, row+1, col+1);
       return dp[row][col] = max(down, max(leftDown, rightDown));
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        n = N-1;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        int maxxi = INT_MIN;
        for (int i = 0;i<N;i++){
           maxxi = max(maxxi, solve(Matrix, dp,0,i));
        }
        return maxxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends