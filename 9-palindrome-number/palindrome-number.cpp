class Solution {
public:
    bool isPalindrome(int x) 
    {
        stack<int> st;
        int origin=x;//storing original value of x
        if(x<0) return false;

        while(x>0)
        {
            st.push(x%10);
            x=x/10;
        }

        x=origin;

        while(!st.empty()) 
        {
            if(st.top() == x%10)
            {
                st.pop();
                x=x/10;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};