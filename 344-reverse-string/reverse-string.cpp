class Solution {
public:
    void helper(vector<char>& s, int i, int j) {
        if (i >= j) return; // Base case: stop when indices cross

        swap(s[i], s[j]); // Swap characters

        helper(s, i + 1, j - 1); // Recursive call moving inward
    }
    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};