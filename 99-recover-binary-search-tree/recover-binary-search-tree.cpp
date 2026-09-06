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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
private:
    void inorder(TreeNode* root){
        if(root == NULL) return; //base case

        inorder(root -> left);//left me phle jaoo

        if( prev!= NULL && (root -> val < prev -> val)){ //condition check kro
            if( first == NULL){// first violation pr first or middle rkh lo mark krke
                first = prev;
                middle = root;
            }
            else{               //second violation pe last mark kr lo
                last = root;
            }
        }
        prev = root;
        inorder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        //saari nodes ko null krlo
        first = middle = last = NULL;

        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last) swap(first -> val,last -> val);
        else if(first && middle){
            swap(first -> val,middle -> val);
        }
    }
};