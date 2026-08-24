class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == NULL) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int lvl = q.size();
            vector<int> temp;
            temp.reserve(lvl);

            while(lvl--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t -> val);

                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);

            }

            res.push_back(temp);
        }

        return res;
        
    }
};