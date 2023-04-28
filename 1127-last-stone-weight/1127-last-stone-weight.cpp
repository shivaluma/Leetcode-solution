class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq; 
        for (auto& stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int firstStone = pq.top();
            pq.pop();
            int secondStone = pq.top();
            pq.pop();
            pq.push(abs(firstStone-secondStone));
        }
        return pq.top();
    }
};