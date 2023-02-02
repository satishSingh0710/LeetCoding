class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string res = "";
        int minString = min(str1.size(), str2.size());
        // int maxxLength = INT_MIN;
        string small,large;
        if (str1.size()<str2.size()){
            small = str1; large = str2;
        }else{
            small = str2; large = str1;
        }
        
        for (int i = 0;i<minString;i++){
            string temp = "";
            for (int j = 0;j<=i;j++){
                temp+= small[j];
            }
            
            string temp2 = "";
            string temp3 = "";
            for (int j = 0;j<large.size();j++){
                temp2 += large[j];
               if (temp2[temp2.size()-1]!=large[j]){
                    break;
                }
                if (temp2==temp){
                    temp2="";
                    continue;
                }
                
                if (temp2.size()>=temp.size() && temp2 != temp){break;}
            }
            
            
            for (int j = 0;j<small.size();j++){
                temp3 += small[j];
                if (temp3[temp3.size()-1]!=small[j]){
                    break;
                }
                if (temp3==temp){
                    temp3="";
                    continue;
                }
                
                if (temp3.size()>=temp.size() && temp3 != temp){break;}
            }
            // cout<<temp2<<" "<<temp3<<" "<<temp<<endl;
            if (temp2 == "" && temp3 == ""){
               if (temp.size()>res.size()){
                   res = temp;
               }
            }
            
            
        }
        
        return res;
        
    }
};