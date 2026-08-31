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
    bool ischeck(TreeNode* root,int value){
        if(!root){
            return true;
        }
        if(root->val != value ){

            return false;
        }

        bool left = ischeck(root->left,value);
        bool right = ischeck(root->right,value);

        if(left == false || right == false){
            return false;
        }

        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        return ischeck(root,root->val);
    }
};