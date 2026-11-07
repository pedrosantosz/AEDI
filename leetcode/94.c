/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void emOrdem(struct TreeNode *root, int *tamanho, int **vetor) {
    if (root == NULL)
        return;
    
    emOrdem(root->left, tamanho, vetor);
    
    *tamanho += 1;
    *vetor = (int *) realloc(*vetor, sizeof(int) * (*tamanho));
    (*vetor)[*tamanho - 1] = root->val;  
    
    emOrdem(root->right, tamanho, vetor);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int *res = (int *) malloc(sizeof(int) * (*returnSize));

    emOrdem(root, returnSize, &res);

    return res;
}