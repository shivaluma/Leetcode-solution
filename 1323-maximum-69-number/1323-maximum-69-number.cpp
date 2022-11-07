class Solution {
public:
    int maximum69Number (int num) {
        string numstr = to_string(num);
        
        for (char &c : numstr) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        
        return stoi(numstr);
        
    }
};