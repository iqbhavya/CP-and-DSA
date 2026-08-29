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
    int sum(TreeNode* root, string a){

        a = a + to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            return stoi(a);
        }
        int left = 0;
        int right = 0;
        if(root->left){
            left = sum(root->left,a);
        }
        
        if(root->right){
            right = sum(root->right,a);
        }

        
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return sum(root,"");
    }
};