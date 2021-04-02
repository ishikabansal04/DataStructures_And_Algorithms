class Solution {
public:
    ListNode* globalhead = NULL;
    
    bool helperfun(ListNode* head){
        if(head == NULL) return true;
        
        bool res = helperfun(head->next);        
        if(res == false) return false;
        res = (head->val == globalhead->val);
        globalhead = globalhead->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        globalhead = head;
        return helperfun(head);
    }
};