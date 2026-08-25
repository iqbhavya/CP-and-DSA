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

    pair<int,int> dia(TreeNode* root){
        if(root == NULL){
            return make_pair(0,0);
        }

        pair<int,int> leftInfo = dia(root->left);
        pair<int,int> rightInfo = dia(root->right);

        int currDia = leftInfo.second + rightInfo.second + 1;
        int finalDia = max(currDia, max(rightInfo.first , leftInfo.first));
        int finalHt = max(leftInfo.second ,rightInfo.second) + 1;

        return make_pair(finalDia , finalHt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int finaldia  = dia(root).first;
        int finalheight = dia(root).second;

        return finaldia - 1;
    }
};