// Find the Pivot Integer

int pivotInteger(int n) {
    int sumI = 0;
    for (int i = 1; i <= n; i++) {
        sumI += i;
        int sumJ = 0;
        for (int j = i; j <= n; j++){
            sumJ += j;
        }

        if (sumI == sumJ)
            return i;
    }

    return -1;
}
