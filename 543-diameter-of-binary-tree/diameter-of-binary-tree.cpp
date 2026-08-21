class Solution {
public:
    pair<int,int> diameter(TreeNode* root){
        //base case 
        if(root == NULL) return {0,0};

        pair<int,int> left = diameter(root -> left);
        pair<int,int> right = diameter(root -> right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(opt1 , max(opt2,opt3));
        ans.second = max(left.second , right.second) + 1;

        return ans;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        return diameter(root).first;
        
    }
};