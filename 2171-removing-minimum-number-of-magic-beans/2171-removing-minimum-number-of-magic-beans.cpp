class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long int sum = 0;
        long long res = LLONG_MAX;
        long long int n = beans.size();
        for (auto &i: beans){sum += (long long)i;}
        long long int pre = 0;
        for (int i = 0;i<n;i++){
            long long int present = (long long)beans[i] * (n-i);
            long long int removals = sum - present; 
            res = min(res, removals);
        }
        return res; 
    }
};