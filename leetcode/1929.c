// 1929. Concatenation of Array

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans;
    *returnSize = numsSize * 2;

    ans = (int *)malloc(*returnSize * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        ans[i] = nums[i % numsSize];
    }
    return ans;
}
