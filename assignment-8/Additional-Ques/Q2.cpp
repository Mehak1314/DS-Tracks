class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            allTrees.push_back(NULL); // no node, return empty tree
            return allTrees;
        }

        // pick each number as root
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // combine left and right subtrees
            for (int l = 0; l < leftTrees.size(); l++) {
                for (int r = 0; r < rightTrees.size(); r++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTrees[l];
                    root->right = rightTrees[r];
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};
