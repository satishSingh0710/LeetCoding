class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (sentence[0] != sentence[n-1])return false;
        bool firstTime = true;
        char previous;
        for (int i = 0;i<n;i++){
             if (sentence[i] == ' '){
                 if (sentence[i+1]!= previous) return false;
             }
            previous = sentence[i];
        }
        return true;
    }
};