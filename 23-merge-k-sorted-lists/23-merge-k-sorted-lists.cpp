
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
        
        if(lists.size() == 0)
            return NULL;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        
        ListNode *temp, *head;
        temp = head = new ListNode();
        while(!pq.empty()){
            ListNode* x = new ListNode(pq.top());
            pq.pop();
            temp->next = x;
            temp = temp->next;
                
        }
        return head->next;
    }
};