class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> ngeMap; // Stores the next greater element for nums2
        stack<int> st; // Monotonic decreasing stack

        // Step 1: Find Next Greater Elements for nums2 using Stack
        for (int i = 0; i < n2; i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                ngeMap[st.top()] = nums2[i]; // Map the next greater element
                st.pop();
            }
            st.push(nums2[i]);
        }

        // Remaining elements in stack have no NGE, mark them as -1
        while (!st.empty()) {
            ngeMap[st.top()] = -1;
            st.pop();
        }

        // Step 2: Populate result for nums1 using the map
        vector<int> result(n1);
        for (int i = 0; i < n1; i++) {
            result[i] = ngeMap[nums1[i]];
        }

        return result;
    }
};