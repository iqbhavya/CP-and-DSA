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
    int minheight(TreeNode* root){

        if(root == NULL){
            return 0;
        }
        int left = minheight(root->left);
        int right = minheight(root->right);

        if(root->left == NULL){
            return right + 1;
        }else if(root->right == NULL){
            return left + 1;
        }

        return min(left,right) + 1;
        
    }
    int minDepth(TreeNode* root) {
        int ans = minheight(root);

        return ans;
    }
};