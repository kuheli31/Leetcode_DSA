class Solution {
public:
    // Helper function to return a pair of <rob, notRob>
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // rob current: root->val + notRob left + notRob right
        int robCurr = root->val + left.second + right.second;

        // not rob current: take max of rob or notRob from left & right
        int notRobCurr = max(left.first, left.second) + max(right.first, right.second);

        return {robCurr, notRobCurr};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
