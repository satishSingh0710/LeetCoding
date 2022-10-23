class Solution {
public:
    bool haveConflict(vector<string>& e, vector<string>& e1) {
       int start = 0, end = 0;
       
            string startTime = "";
            string endTime = "";
            for (int i = 0;i<e.size();i++){
                for (int j = 0;j<e[0].size();j++){
                   if (i == 0){ if (e[i][j]==':') continue; startTime += e[i][j];}
                   if (i==1){if (e[i][j]==':') continue; endTime += e[i][j];}
                }
            }
            start = stoi(startTime);
            end= stoi(endTime);
        
            string nextStart="";
            string nextEnd = "";
        
            for (int i = 0;i<e1.size();i++){
                for (int j = 0;j<e1[0].size();j++){
                   if (i == 0){if (e1[i][j]==':') continue;nextStart += e1[i][j];}
                   if (i==1){if (e1[i][j]==':') continue; nextEnd += e1[i][j];}
                }
            }
        
         cout<<startTime<<" "<<endTime<<":::"<<stoi(nextStart)<<" "<<stoi(nextEnd)<<endl;
           int ns = stoi(nextStart); int ne = stoi(nextEnd);
          if (ns>=start  && ns<= end) return true;
          if (ne <= end && ne>=start) return true;
          if (start>=ns && start<= ne) return true;
          if (end<= ne && end>= ns) return true;
        return false;
        
    }
};