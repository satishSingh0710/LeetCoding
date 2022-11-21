class Solution {
public:
    vector<vector<int>> ways = {{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int,int>> q;
        int length = 1;
        q.push({e[0], e[1]});
        maze[e[0]][e[1]] = '+';
        while(!q.empty()){
            int size = q.size(); 
            for (int i= 0;i<size;i++){
                auto temp = q.front(); q.pop();
                
                for (int j = 0;j<4;j++){
                    int newRow = temp.first + ways[j][0];
                    int newCol = temp.second + ways[j][1];
                    
                    if (newRow<0||newCol <0||newRow>=m||newCol>=n)continue;
                    if (maze[newRow][newCol] == '.'){
                        if (newRow == 0 || newCol == 0 || newRow ==m-1 || newCol == n-1){
                            return length;
                        }
                        maze[newRow][newCol] = '+';
                        q.push({newRow, newCol});
                    }
                    
                }
            }
            length++;
        }
        
        return -1;
    }
};