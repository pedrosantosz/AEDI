/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void vetor(struct TreeNode *root, int **vet, int *tam) {
    if (root == NULL) {
        return;
    }

    vetor(root->left, vet, tam);

    *vet = realloc(*vet, sizeof(int) * (*tam + 1));
    (*vet)[*tam] = root->val;
    *tam += 1;

    vetor(root->right, vet, tam);
}

int kthSmallest(struct TreeNode* root, int k) {
    int *vetorOrdenado;
    int tamanho = 0;
    vetorOrdenado = malloc(0);

    vetor(root, &vetorOrdenado, &tamanho);

    int kValor = vetorOrdenado[k - 1];
    free(vetorOrdenado);

    return kValor;
}