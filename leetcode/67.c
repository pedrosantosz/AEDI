char* addBinary(char* a, char* b) {
    int size_a;
    int size_b;
    int greater;

    for(size_a = 0; a[size_a] != '\0'; size_a++);
    for(size_b = 0; b[size_b] != '\0'; size_b++);

    if (size_a > size_b) {greater = size_a;}
    else {greater = size_b;}


    char carry = '0';
    
    char *ans = (char *) malloc(sizeof(char) * (greater + 2)); // nro caracteres +  \0 e possivel carry final = 1
    
    int last = greater + 1;
    ans[last] = '\0';
    last--;

    int i = size_a - 1;
    int j = size_b - 1;

    char x, y;

    while (i >= 0 || j >= 0) {
        if (i >= 0)
            x = a[i];
        else 
            x = '0';

        if (j >= 0)
            y = b[j];
        else 
            y = '0';

        if (carry == '0') {
            if (x != y) {
                // r = 1; c = 0 (continua)
                ans[last] = '1';
            } else {
                // r = 0
                ans[last] = '0';
                if (x == '1')
                    carry = '1';
            }
        } else {
            if (x != y) {
                // r = 0; c = 1 (continua)
                ans[last] = '0';
            } else {
                ans[last] = '1';
                if (x == '0')
                    carry = '0';
            }
        }

        i--;
        j--;
        last--;
    }

    if (carry == '0') {
        int i;
        for (i = 0; i < (greater); i++) {
            ans[i] = ans[i+1];
        }
        ans[i] = '\0';

        ans = (char *) realloc(ans, sizeof(char) * (greater + 1));
    } else {
        ans[0] = '1';
    }

    return ans;
}