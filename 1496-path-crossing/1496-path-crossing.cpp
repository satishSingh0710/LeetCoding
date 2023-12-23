class Solution {
public:
    bool isPathCrossing(string path) {
       set<pair<int,int>> st; 
        int x = 0, y = 0;
        st.insert({x,y}); 
        for (auto &i: path){
            if(i == 'N'){
                x++; 
                if(st.count({x,y})) return true; 
                st.insert({x,y}); 
            }else if(i == 'S'){
                x--; 
                if(st.count({x,y})) return true; 
                st.insert({x,y}); 
            }else if(i == 'W'){
                y--; 
                if(st.count({x,y})) return true; 
                st.insert({x,y}); 
            }else{
                y++;
                if(st.count({x,y})) return true; 
                st.insert({x,y}); 
            }
        }
        return false; 
    }
};