static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int firstUniqChar(string s) {
        int mp[256];
        memset(mp, 0, sizeof(mp));
        int len = s.size();
        for (int i = 0; i < len; i++) {
            mp[int(s[i])]++;
        }
        for (int i = 0; i < len; i++) {
            if (mp[int(s[i])] == 1) return i;
        }
        return -1;
    }
};