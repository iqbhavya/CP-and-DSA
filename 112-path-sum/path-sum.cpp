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
    bool hasPath(TreeNode* root, int targetSum, int curr){
        if (root == NULL)
            return false;

        curr += root->val;

        
        if (root->left == NULL && root->right == NULL) {
            return curr == targetSum;
        }
        
        

        

        return hasPath(root->left,targetSum,curr) ||
        hasPath(root->right,targetSum,curr);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPath(root,targetSum,0);
    }
};