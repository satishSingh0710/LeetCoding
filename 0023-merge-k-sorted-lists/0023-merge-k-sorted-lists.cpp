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
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> s;
        for (int i = 0;i<lists.size();i++){
            ListNode * head = lists[i];
            while(head){
                s.insert(head->val); head = head->next;
            }
        }
        ListNode *tail = new ListNode(0);
        ListNode * res = tail;
        for (auto &i: s){
             ListNode * head = new ListNode(i);
             tail->next = head; tail = head; 
        }
       
        return res->next;
    }
    
    
};