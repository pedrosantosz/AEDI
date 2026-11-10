/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getMax(struct TreeNode *root) {
    while(root->right != NULL) {
        root = root->right;
    }

    return root->val;
}

int getMin(struct TreeNode *root) {
    while(root->left != NULL) {
        root = root->left;
    }

    return root->val;
}

int menor(int a, int b) {
    return a < b? a : b;
}

int getMinimumDifference(struct TreeNode* root) {
    int min = 100000;
    
    if (root == NULL) {
        return min;
    }
    int a = 100000, b = 100000;

    if (root->left != NULL) {
        a = root->val - getMax(root->left);
    }
    
    if (root->right != NULL) {
        b = getMin(root->right) - root->val;
    }

    min = menor(a, b);

    a = getMinimumDifference(root->left);
    b = getMinimumDifference(root->right);

    min = menor(min, menor(a,b));

    return min;

}