int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int *ans = (int *) malloc(sizeof(int) * (*returnSize));
    
    int i, j;
    i = 0;
    j = numbersSize - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] == target) {
            ans[0] = i + 1;
            ans[1] = j + 1;
            return ans;
        } else if (numbers[i] + numbers[j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return ans;
}