class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) {
            return 0;
        }

        else if(!list1) {
            return list2;
        }

        else if(!list2) {
            return list1;
        }
        
        ListNode* answer { new ListNode() };
        ListNode* head { answer };

        while(list1 && list2) {
            if(list1->val >= list2->val) {
                answer->next = list2;
                list2 = list2->next;
            }

            else {
                answer->next = list1;
                list1 = list1->next;
            }

            answer = answer->next;
        }

        if(list1) {
            answer->next = list1;
        }

        else {
            answer->next = list2;
        }

        return head->next;
    }
};