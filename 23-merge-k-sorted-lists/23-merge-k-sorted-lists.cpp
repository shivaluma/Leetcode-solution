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
        ListNode* res = nullptr;
        ListNode* curr = nullptr;
        while(lists.size()){
            int idx = 0;
            if(!lists[idx]) {
                lists.erase(lists.begin() + idx);
                continue;
            }
            for(int i = 1; i < lists.size(); i++){
                if(lists[i] && lists[idx]->val > lists[i]->val) {
                    idx = i;
                }
            }
                        
            if(!curr) curr = lists[idx];
            else { 
                curr->next = lists[idx];
                curr = curr->next;
            }
            if(!res) res = curr;

            if(lists[idx]) lists[idx] = lists[idx]->next;
            if(lists[idx] == nullptr) lists.erase(lists.begin() + idx);
        }
        
        return res;
    }
};