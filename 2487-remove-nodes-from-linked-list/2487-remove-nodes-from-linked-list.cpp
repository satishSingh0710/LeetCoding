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
    void reverse(ListNode * root, vector<int> &reverseList){
        if (root){
            reverseList.push_back(root->val);
            reverse(root->next, reverseList);
        }
    }
    
    ListNode* removeNodes(ListNode* head) {
        vector<int> reverseList;
        reverse(head, reverseList);
        // reverse(reverseList.begin(), reverseList.end());
        stack<int> st;
        st.push(-1);
        
        for (int i = reverseList.size()-1;i>=0;i--){
            while(st.top()!= -1 && st.top() <= reverseList[i] ){
                st.pop();
            }
            int temp = reverseList[i];
            reverseList[i] = st.top();
            st.push(temp);
        }
        ListNode * temp = head;
        for (auto &i: reverseList){
            // cout<<i<<" ";
            if (i != -1){
                temp->val = -1;
            }
            temp = temp->next;
        }
        // cout<<endl;
        ListNode * p = head;
        ListNode * q = head->next;
        while(p){
            if (p->val == -1 && p == head){
                head = p->next;
                p->next = NULL;
                delete(p);
                p = head;
                q = p->next;
            }else if (q){
                if (q->val == -1){
                    p->next = q->next;
                    q->next = NULL;
                    delete(q);
                    q = p->next;
                }else{
                    p = p->next;
                    q = q->next;
                }
                
            }else{
                p = p->next;
            }
           
        }
        
        return head;
        
    }
};