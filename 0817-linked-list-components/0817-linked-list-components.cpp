/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,bool> mp; 
        int res = 0,component = 0;
        for (auto &i: nums){mp[i] = true;}
        ListNode * p  =  head; 
        while(p){ if (mp[p->val]==false){p->val = -1;} p = p->next;}
        p = head; 
        
        while(p){
            if (p->val != -1){component++;}
            if (p->val == -1 && component>0){
                res++; component = 0;
            } else if (p->val != -1 && p->next == NULL){res++;}
            p = p->next;
        }
        
        return res;
        
    }
};