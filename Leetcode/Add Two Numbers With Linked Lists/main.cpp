class Solution {
public:
    ListNode* addTwoNumbers(ListNode* node1, ListNode* node2) {

        ListNode* temp { new ListNode() };
        ListNode* answer { temp };

        int carry { 0 };

        while((node1) || (node2) || (carry)) {
            int sum { 0 };

            if(node1) {
                sum += node1->val;
                node1 = node1->next;
            }

            if(node2) {
                sum += node2->val;
                node2 = node2->next;
            }

            sum += carry;
            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return answer->next;
    }
};