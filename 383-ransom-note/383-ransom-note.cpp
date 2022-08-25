static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> char_freq_for_note(128);
        for (auto c : ransomNote)
        {
            ++char_freq_for_note[c];
        }

        for (auto c : magazine)
        {
            --char_freq_for_note[c];
        }
        return std::none_of(cbegin(char_freq_for_note),
                            cend(char_freq_for_note),
                            [](int x) { return x > 0; });
    }
};