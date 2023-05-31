bool comparePairs(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
    return p1.second > p2.second;
}

class Solution {
public:

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // build a 
        // 
        int n = nums1.size();
        vector<pair<int,int>> pairs(n);

        // maintaining a top k biggest element in current_sum;
        priority_queue<int, vector<int>, greater<int>> pq;

        long long ans = 0;
        long long current_sum = 0;

        for (int i = 0; i < n; i++) {
            pairs.push_back({nums1[i], nums2[i]});
        }

        std::sort(pairs.begin(), pairs.end(), comparePairs);

        for (int i = 0; i < k; i++) {
            current_sum += pairs[i].first;
            pq.push(pairs[i].first);
        }

        ans = current_sum * pairs[k-1].second;

        for (int i = k; i < n; i++) {
            // remove the smallest from top k largest element.
            int smallest = pq.top();
            pq.pop();
            // add current number to top K
            pq.push(pairs[i].first);

            current_sum += pairs[i].first - smallest;
            
            long long new_value = current_sum * pairs[i].second;
            
            ans = max(ans, new_value);
        }

        return ans;
    }
};