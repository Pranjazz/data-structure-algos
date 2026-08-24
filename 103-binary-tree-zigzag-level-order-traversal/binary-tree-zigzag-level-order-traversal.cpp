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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == NULL) return {};

        queue<TreeNode*> q;
        q.push(root);

        bool rightToleft=0;
        vector<vector<int>> res;
        
        while(!q.empty()){
            int level = q.size();
            vector<int> temp(level);

            for(int i=0;i<level;i++){
                TreeNode* t = q.front();
                q.pop();
                
                int index = rightToleft? (level - i - 1) : i;

                temp[index] = t -> val;

                if( t-> left) q.push(t -> left);
                if( t-> right) q.push(t -> right);

            }
            rightToleft = !rightToleft;
            res.push_back(temp);
        }
        return res;
    }
};