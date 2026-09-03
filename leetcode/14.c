char* longestCommonPrefix(char** strs, int strsSize) {
    
    char *ans = (char *) malloc(sizeof(char) * 1);
    ans[0] = '\0';
    
    int l = 0, c = 0;
    char ch;

    while (l < strsSize) {
        ch = strs[0][c];

        if (strs[l][c] == '\0' || ch != strs[l][c]) {
            ans[c] = '\0';
            return ans;
        }

        l++;

        if (l == strsSize) {
            ans = (char *) realloc(ans, sizeof(char) * ((c + 1) + 1)); // c+1 = chars; +1 = \0
            ans[c] = ch;
            
            l = 0;
            c++;
        }
    }
    
    ans[c] = '\0';

    return ans;
}