class Solution {
public:

    TreeNode* createParentMapping(
        TreeNode* root,
        int start,
        unordered_map<TreeNode*, TreeNode*>& parent
    ) {
        queue<TreeNode*> q;
        q.push(root);

        parent[root] = NULL;

        TreeNode* startNode = NULL;

        while (!q.empty()) {

            TreeNode* front = q.front();
            q.pop();

            if (front->val == start) {
                startNode = front;
            }

            if (front->left) {
                parent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                parent[front->right] = front;
                q.push(front->right);
            }
        }

        return startNode;
    }


    int burnTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front();
                q.pop();

                // Left
                if (front->left && !visited[front->left]) {
                    flag = true;

                    q.push(front->left);
                    visited[front->left] = true;
                }

                // Right
                if (front->right && !visited[front->right]) {
                    flag = true;

                    q.push(front->right);
                    visited[front->right] = true;
                }

                // Parent
                if (parent[front] && !visited[parent[front]]) {
                    flag = true;

                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
            }

            if (flag) {
                time++;
            }
        }

        return time;
    }


    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* startNode =
            createParentMapping(root, start, parent);

        return burnTree(startNode, parent);
    }
};