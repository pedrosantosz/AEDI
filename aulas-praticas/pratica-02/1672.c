int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int richest_wealth = 0;

    for (int i = 0; i < accountsSize; i++) {
        int wealth = 0;
        for (int j = 0; j < *accountsColSize; j++) {
            wealth += accounts[i][j];
        }
        if (wealth > richest_wealth)
            richest_wealth = wealth;
    }

    return richest_wealth;
}