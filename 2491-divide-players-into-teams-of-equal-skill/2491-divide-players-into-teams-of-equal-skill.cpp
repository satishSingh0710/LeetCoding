class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i = 0, j = skill.size()-1;
        int team = INT_MIN;
        long long int chemistry = 0;
        while(i<j){
            chemistry += skill[i]*skill[j];
            if  (team == INT_MIN){
                team = skill[i] + skill[j];
            }else{
                if (skill[i] + skill[j] != team) return -1;
            }
            i++; j--;
        }
        
        return chemistry;
    }
};