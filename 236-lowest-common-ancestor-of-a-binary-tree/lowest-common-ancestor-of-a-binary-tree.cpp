class Solution {
public:

    TreeNode* lca(TreeNode* root, TreeNode* p,TreeNode* q){
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }

        TreeNode* left = lca(root->left,p,q);
        TreeNode* right = lca(root->right,p,q);

        if(left != NULL && right != NULL){
            return root;
        }

        return left == NULL ? right : left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};