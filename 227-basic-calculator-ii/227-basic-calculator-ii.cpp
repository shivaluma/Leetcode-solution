class Solution {
public:
    int calculate(string s) {

        int i = 0;
        int n = s.length();
        
        int ans = 0, num = 0;
        
        stack<int> st;
        char currentOperator = '+';
        
        while (i < n) {
            if (isdigit(s[i])) {
                string temp;
                while(s[i]>='0'  && s[i]<='9' && i <= n - 1){
                    temp+=s[i];
                    i++;
                }
                i--;
                num = stoi(temp);
            }
            
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                if (currentOperator == '+') {
                    st.push(num);
                } else if (currentOperator == '-') {
                    st.push(-num);
                } else if (currentOperator == '*') {
                    int lhs = st.top(); st.pop();
                    st.push(lhs * num);
                } else if (currentOperator == '/') {
                    int lhs = st.top(); st.pop();
                    st.push(lhs / num);
                } 
                currentOperator = s[i];
                num = 0;
            }
            
            i++;
        }
        
        
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }
        
        return ans;
    }
};