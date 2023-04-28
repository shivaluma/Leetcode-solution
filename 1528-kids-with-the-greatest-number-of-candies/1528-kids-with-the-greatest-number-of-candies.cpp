class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candie = 0;

        for (int cand : candies) {
            max_candie = max(cand, max_candie);
        }

        vector<bool> ans(candies.size(), false);

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max_candie) {
                ans[i] = true;
            }
        }

        return ans;
    }
};