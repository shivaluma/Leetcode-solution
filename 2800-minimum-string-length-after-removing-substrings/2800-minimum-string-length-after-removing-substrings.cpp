class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if (st.size() > 0) {
                if (c == 'B' && st.top() == 'A') {
                    st.pop();
                    continue;
                }

                if (c == 'D' && st.top() == 'C') {
                    st.pop();
                    continue;
                }
            } 

            st.push(c);
        }

        return st.size();
    }
};