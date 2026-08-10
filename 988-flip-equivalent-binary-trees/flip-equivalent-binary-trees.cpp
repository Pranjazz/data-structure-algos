class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        // Both are NULL
        if (root1 == NULL && root2 == NULL)
            return true;

        // One is NULL
        if (root1 == NULL || root2 == NULL)
            return false;

        // Values must be equal
        if (root1->val != root2->val)
            return false;

        // Case 1: Don't flip
        bool noFlip =
            flipEquiv(root1->left, root2->left) &&
            flipEquiv(root1->right, root2->right);

        // Case 2: Flip
        bool flip =
            flipEquiv(root1->left, root2->right) &&
            flipEquiv(root1->right, root2->left);

        return noFlip || flip;
    }
};