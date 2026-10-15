typedef struct {
    int x, y;
    int dist;
} Ponto;

typedef struct Nodo{
    Ponto p;
    struct Nodo *pProx;
    struct Nodo *pAnt;
} Nodo;

typedef struct {
    Nodo *primeiro;
    Nodo *ultimo;
} Fila;

Fila *CriaFila() {

    Fila *nova_fila = (Fila *) malloc(sizeof(Fila));

    nova_fila->primeiro = NULL;
    nova_fila->ultimo = NULL;

    return nova_fila;
}

Ponto NovoPonto(int x, int y) {
    Ponto novo_ponto;
    
    novo_ponto.x = x;
    novo_ponto.y = y;
    novo_ponto.dist = (x - 0) * (x - 0) + (y - 0) * (y - 0);

    return novo_ponto;
}

int Adiciona(Fila *fila, Ponto ponto) {
    Nodo *novo_nodo = (Nodo *) malloc(sizeof(Nodo));

    if (novo_nodo == NULL) {
        return 0;
    }

    novo_nodo->p = ponto;
    novo_nodo->pProx = NULL;
    novo_nodo->pAnt = fila->ultimo;

    if (fila->primeiro == NULL) {
        fila->primeiro = novo_nodo;
    } else {
        (fila->ultimo)->pProx = novo_nodo;
    }

    fila->ultimo = novo_nodo;

    return 1;
}

Ponto MenorDistancia(Fila *fila) {
    Ponto pt;

    int menor = (fila->primeiro)->p.dist;
    
    Nodo *removido;
    
    for (Nodo *atual = (fila->primeiro); atual != NULL; atual = atual->pProx) {
        if (atual->p.dist <= menor) {
            removido = atual;
            menor = atual->p.dist;
        }
    }

    pt.x = removido->p.x;
    pt.y = removido->p.y;

    if (removido->pAnt == NULL) {
        (removido->pProx)->pAnt = NULL;
        fila->primeiro = removido->pProx;
    } else if (removido->pProx == NULL) {
        (removido->pAnt)->pProx = NULL;
        fila->ultimo = removido->pAnt;
    } else {
        (removido->pAnt)->pProx = removido->pProx;
        (removido->pProx)->pAnt = removido->pAnt;
    }

    free(removido);

    return pt;
}

void Clear(Fila *fila) {
    Nodo *atual = fila->primeiro;
    while (atual != NULL) {
        Nodo *prox = atual->pProx;
        free(atual);
        atual = prox;
    }
    free(fila);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = k;
    *returnColumnSizes = (int *) malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    if (k == pointsSize) {
        return points;
    }

    int **res = (int **) malloc(sizeof(int *) * k);

    for (int i = 0; i < k; i++) {
        res[i] = (int *) malloc(sizeof(int) * 2);
    }

    Fila *FPontos = CriaFila();
    
    for (int i = 0; i < pointsSize; i++) {
        Adiciona(FPontos, NovoPonto(points[i][0], points[i][1]));
    }

    for (int i = 0; i < k; i++) {
        Ponto p = MenorDistancia(FPontos);
        res[i][0] = p.x;
        res[i][1] = p.y;
    }

    Clear(FPontos);

    return res;
}