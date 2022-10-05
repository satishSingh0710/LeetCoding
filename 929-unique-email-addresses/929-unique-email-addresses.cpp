class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        
        for (string &x: emails){
                    bool foundAt = false, foundPlus = false;

            string local = "";
            for (char &y: x){
                if (foundPlus==false){
                     if (y=='@'){foundAt = true;}
                    if (y =='.'&&foundAt==false) continue;
                    if (y=='+'){foundPlus = true; continue;}
                    local.push_back(y);
                }else{
                    if (y=='@'){foundAt = true;}
                    if (foundAt){
                        local.push_back(y);
                    }
                }
            }
           cout<<local<<endl;
            s.insert(local);
        }
        return s.size();
    }
};