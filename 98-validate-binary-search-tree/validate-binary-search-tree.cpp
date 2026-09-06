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
    bool valid(TreeNode* root ,long long maxValue ,long long minValue){
        if(root == NULL) return true;

        if(root -> val >= maxValue || root -> val <= minValue){
            return false;
        }

        return valid(root -> left,root -> val,minValue) && valid(root -> right,maxValue,root -> val);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MAX,LLONG_MIN);
    }
};