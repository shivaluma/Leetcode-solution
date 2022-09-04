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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* headAns = new ListNode(0);
        ListNode* tailAns = headAns;

        while (lists.size()) {
            int minIdx = 0;
            for (int i = 0; i < lists.size(); i++) {  
                
                if (!lists[i]) {
                    lists.erase(lists.begin() + i);
                }
                
                if (lists[i] && lists[i]->val < lists[minIdx]->val) {
                    minIdx = i;
                }
            }
            
           
            
            tailAns->next = lists[minIdx];
            if (lists[minIdx]) lists[minIdx] = lists[minIdx]->next;
            if (tailAns->next) tailAns = tailAns->next;
        }
        
        return headAns->next;
    }
};