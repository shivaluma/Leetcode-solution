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
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL) return head;

        ListNode* ph = NULL;
        ListNode* h = head;
        ListNode* hn = head->next;

        if (hn == NULL) return head;

        ListNode* ans = head->next;
        while (h != NULL && hn != NULL) {
            h->next = hn->next;
            hn->next = h;
            if (ph) ph->next = hn;
            ph = h;
            if (h->next) {
                h = h->next;
                if (h->next) {
                    hn = h->next;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        return ans;
    }
};