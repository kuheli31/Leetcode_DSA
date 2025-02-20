class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> day(n,0);
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }
            if(!st.empty()) 
            {
                day[i]=st.top() - i;
            }
            st.push(i);
        }
        return day;
    }
};