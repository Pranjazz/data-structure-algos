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
    pair<bool,int> balance(TreeNode* root){
        if(root == NULL) return {true,0};

        //pair me bna lo , first me balance , second me diff

        pair<bool,int> left = balance(root -> left);
        pair<bool,int> right = balance(root -> right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second ) <= 1;

        pair<bool,int> ans;
        ans.second = max(left.second , right.second)+ 1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;
    }
    bool isBalanced(TreeNode* root) {

        if( root == NULL) return true;

        return balance(root).first;
        
    }
};