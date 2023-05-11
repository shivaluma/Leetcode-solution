/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* turtle = head;
        ListNode* rabbit = head;

        while (turtle && rabbit) {
            turtle = turtle->next;
            if (rabbit->next) {
                rabbit = rabbit->next->next;
            } else {
                return false;
            }

            if (turtle != NULL && turtle == rabbit) {
                return true;
            }
        }

        return false;
    }
};