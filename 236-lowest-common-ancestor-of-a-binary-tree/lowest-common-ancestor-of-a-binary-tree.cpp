class Solution {
public:

    bool rootToNodePath(TreeNode* root, TreeNode* target, 
                        vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }

        path.push_back(root);

        if (root == target) {
            return true;
        }

        bool isLeft = rootToNodePath(root->left, target, path);
        bool isRight = rootToNodePath(root->right, target, path);

        if (isLeft || isRight) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);

        TreeNode* lca = NULL;

        for (int i = 0, j = 0;
             i < path1.size() && j < path2.size();
             i++, j++) {

            if (path1[i] != path2[j]) {
                break;
            }

            lca = path1[i];
        }

        return lca;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};