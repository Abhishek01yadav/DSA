
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
          ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // i ll find the staring point of the cycle or loop.
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
           
           
        }
        return NULL;
        
    }
};