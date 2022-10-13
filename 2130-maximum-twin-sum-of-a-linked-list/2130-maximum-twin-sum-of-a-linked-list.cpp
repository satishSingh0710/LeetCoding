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
    int pairSum(ListNode* head) {
        vector<int> temp;
        
        while(head){temp.push_back(head->val); head = head->next;}
        int i = 0, j = temp.size()-1,maxSum = INT_MIN;
        while(i<j){
            int sum = temp[i] + temp[j];
            maxSum = max(maxSum, sum);
            i++; j--;
        }
        return maxSum;
    }
};