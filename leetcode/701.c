/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode *new_node;
        new_node = (struct TreeNode *) malloc(sizeof(struct TreeNode));

        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}