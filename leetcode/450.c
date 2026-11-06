/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* max(struct TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode *son;
            son = root->right;
            free(root);
            return son;
        }

        if (root->right == NULL) {
            struct TreeNode *son;
            son = root->left;
            free(root);
            return son;
        }

        struct TreeNode *substitute;
        substitute = max(root->left);
        root->val = substitute->val;
        root->left = deleteNode(root->left, substitute->val);
    }

    return root;
}