class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        stack<int> st;
        int n=s.size();
        int i;
        for(i=0; i<n ; i++)
        {
            st.push(s[i]);
        }
        for(i=0; i<n ; i++)
        {
            s[i]=st.top();
            st.pop();
        }
    }
};