/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool valida(struct TreeNode *root, int *inferior, int *superior) {
    if (root == NULL) {
        return true;
    }

    if (inferior != NULL && root->val <= *inferior) {
        return false;
    }

    if (superior != NULL && root->val >= *superior) {
        return false;
    }

    return valida(root->left, inferior, &(root->val)) && valida(root->right, &(root->val), superior);    
}

bool isValidBST(struct TreeNode* root) {
    return valida(root, NULL, NULL);
}