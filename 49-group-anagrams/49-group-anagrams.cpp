class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for (string str : strs) {
            string dump = str;
            sort(dump.begin(), dump.end());
            m[dump].push_back(str);
        }

        for (auto const& [key, val] : m) {
            result.push_back(val);
        }

        return result;
    }
};