class Solution {
public:
   
    string countAndSay(int n) {
        string res = "";
        for (int i  = 1;i<=n;i++){
          if (res=="") {res += to_string(i); continue;}
            string temp = ""; int count = 0; char prev = res[0];
             for (int j = 0;j<res.size();j++){
                 if (res[j] != prev){
                     temp+= to_string(count); 
                     temp+= prev;
                     count = 0; prev = res[j];
                 }
                
                 count++;
                 if (j == res.size() -1 && count>0){
                     temp += to_string(count); temp+= prev;
                 }
             }
            // cout<<temp<<endl;
            res = temp;
        }
        
        return res;
    }
};