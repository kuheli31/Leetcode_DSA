class Solution {
public:
    bool isValid(string s) {
        int i;
        int n = s.length();
        stack<char> st;

        for (i = 0; i < n ; i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                else {
                    char top = st.top();
                    if ((top == '[' && s[i] == ']') ||
                        (top == '(' && s[i] == ')') ||
                        (top == '{' && s[i] == '}')) {
                            st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};