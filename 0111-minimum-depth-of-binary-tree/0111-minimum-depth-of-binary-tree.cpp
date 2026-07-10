class Solution {
public:
    // Keeps your original helper function structure intact
    bool leaf(TreeNode* root)
    {
        if(root == NULL) return false;

        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }
        return false;
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        // 1. If it's a leaf node, the depth is just this 1 node.
        if(leaf(root)) return 1;

        // 2. If the left child is missing, we MUST force the path down the right child.
        if(root->left == NULL) return 1 + minDepth(root->right);

        // 3. If the right child is missing, we MUST force the path down the left child.
        if(root->right == NULL) return 1 + minDepth(root->left);

        // 4. If both children exist, we safely take the minimum of both paths.
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return 1 + min(left, right);
    }
};