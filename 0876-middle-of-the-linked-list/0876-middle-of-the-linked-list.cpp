class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * p = head;
        ListNode * q = head;
        
        while (true)
        {
           
            if (q==NULL || q->next == NULL)
                break;
            q= q->next->next;
            p = p->next;
        }
        
        return p;
    }
};