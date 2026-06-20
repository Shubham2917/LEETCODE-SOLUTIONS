class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode * prev = &dummy;


        while(l1 && l2){
            ListNode * node = new ListNode;
            node->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            prev->next = node;
            prev = prev->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ListNode * node = new ListNode;
            node->val = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            prev->next = node;
            prev = prev->next; 
            l1 = l1->next;
        }
        while(l2){
            ListNode * node = new ListNode;
            node->val = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            prev->next = node;
            prev = prev->next; 
            l2 = l2->next;
        }
        if(carry){
           
            ListNode * node = new ListNode;
            node->val = carry;
            prev->next = node;
            prev = prev->next; 
        }
        return dummy.next;
    }
};