class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>res;
        for (int i = 0;i<emails.size();i++){
            string mail = ""; bool foundPlus = false,foundAt = false;
            for (int j = 0;j<emails[i].size();j++){
                cout<<mail<<endl;
                char c = emails[i][j];
                if (c=='.' && foundAt == false)continue;
                if (c=='+'){
                   foundPlus = true;
                } if (c=='@'){
                       mail.push_back(c);
                   foundPlus = false;
                   foundAt = true;
                }else{
                    if (foundPlus==false)
                    mail.push_back(c);
                }
            }
            res[mail]++;
        }
        return res.size();
    }
};