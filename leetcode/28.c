int strStr(char* haystack, char* needle) {
    int n_length;
    
    for (n_length = 0; needle[n_length] != '\0'; n_length++);
    
    int i, j;
    
    for (i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0]) {
            for (j = 0; haystack[i+j] != '\0' && needle[j] != '\0' && haystack[i+j] == needle[j]; j++);
            
            if (j == n_length)
                return i;
        }
    }
    
    return -1;
}