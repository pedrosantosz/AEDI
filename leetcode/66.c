int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    
    *returnSize = digitsSize;
    
    int *ans = (int *) malloc(sizeof(int) * (*returnSize));
    
    for (int i = digitsSize - 1; i >= 0; i--) {
        int result = digits[i] + carry;
        
        if (result <= 9) {
            ans[i] = result;
            carry = 0;
        } else {
            ans[i] = 0;
            carry = 1;
        }
    }
    
    if (carry) {
        *returnSize += 1;
        ans = realloc(ans, sizeof(int) * ( *returnSize ));
        ans[0] = 1;
        ans[*returnSize - 1] = 0;
    }
    
    return ans;
}