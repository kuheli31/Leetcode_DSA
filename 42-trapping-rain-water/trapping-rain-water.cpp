class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int total = 0;
        int current = 0;

        while (current < n) {
            // If the stack is not empty and the current bar is taller than the bar at the top of the stack
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                total += distance * bounded_height;
            }
            st.push(current);
            current++;
        }
        return total;
    }
};
