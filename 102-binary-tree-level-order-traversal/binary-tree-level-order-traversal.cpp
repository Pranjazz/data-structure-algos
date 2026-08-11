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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if( root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;

        while(!q.empty()){
            int lvl = q.size();
            vector<int> temp;
            temp.reserve(lvl);

            while(lvl--){
                TreeNode * t = q.front();
                q.pop();
                temp.push_back(t-> val);
                if( t -> left) q.push(t-> left);
                if( t -> right) q.push(t-> right);
            }

        res.push_back(temp);
        }

        return res;

    }
};