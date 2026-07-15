/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leaf(TreeNode* node)
    {
        if(node->left==nullptr && node->right==nullptr)
        {
            return true;
        }
        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;

        int sum=0;
        if(root->left != nullptr && leaf(root->left))
        {
            sum += root->left->val;
        }
        else 
        {
            sum +=sumOfLeftLeaves(root->left);
        }

        sum +=sumOfLeftLeaves(root->right);

        return sum;
    }
};