// 1502. Can Make Arithmetic Progression From Sequence

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    // bubble sort
    int aux;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i; j < arrSize; j++) {
            if (arr[j] < arr[i]) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }

    // difference
    int difference = arr[1] - arr[0];

    // is an a.p?
    for (int i = 0; i < arrSize - 1; i++) {
        if (arr[i+1] - arr[i] != difference)
            return false;
    }

    return true;
}
