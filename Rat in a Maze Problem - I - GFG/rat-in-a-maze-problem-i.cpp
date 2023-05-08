//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> res; 
    void solve(vector<vector<int>> &maze, int row, int col, int n, string path){
        if(row<0||col<0||row>=n||col>=n||maze[row][col] == 0){
            return;
        }
        if(row == n-1 && col==n-1){
            res.push_back(path);
            return;
        }
        maze[row][col] = 0;
        solve(maze, row,col-1, n, path + "L");
        solve(maze, row, col+1, n, path+"R");
        solve(maze, row+1, col, n, path + "D"); 
        solve(maze, row-1, col, n , path+ "U");
        maze[row][col] = 1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        solve(m, 0,0,n, ""); 
        return res; 
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends