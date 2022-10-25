class Solution {
public:
    string interpret(string command) {
        string res = "";
        for (int i = 0;i<command.size();i++){
            if (command[i] == 'G') res+="G";
            if (command[i] == 'a') res+= "al";
            if (command[i] == '(' && command[i+1] == ')') res+= "o";
        }
        return res;
    }
};