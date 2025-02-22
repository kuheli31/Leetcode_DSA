class Solution {
public:
    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> left(n), right(n);
        
        // Find previous less element index (left boundary)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) 
                st.pop();
            left[i] = (st.empty()) ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear the stack for next computation
        while (!st.empty()) st.pop();
        
        // Find next less element index (right boundary)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) 
                st.pop();
            right[i] = (st.empty()) ? n - i : st.top() - i;
            st.push(i);
        }
        
        // Calculate sum of max elements in subarrays
        long long sumMax = 0;
        for (int i = 0; i < n; i++) {
            sumMax += (long long) nums[i] * left[i] * right[i];
        }
        return sumMax;
    }

    long long sumMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> left(n), right(n);
        
        // Find previous greater element index (left boundary)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) 
                st.pop();
            left[i] = (st.empty()) ? i + 1 : i - st.top();
            st.push(i);
        }

        // Clear the stack for next computation
        while (!st.empty()) st.pop();
        
        // Find next greater element index (right boundary)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) 
                st.pop();
            right[i] = (st.empty()) ? n - i : st.top() - i;
            st.push(i);
        }
        
        // Calculate sum of min elements in subarrays
        long long sumMin = 0;
        for (int i = 0; i < n; i++) {
            sumMin += (long long) nums[i] * left[i] * right[i];
        }
        return sumMin;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};
