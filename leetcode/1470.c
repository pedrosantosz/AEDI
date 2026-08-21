// 1470. Shuffle the Array

int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = 2 * n;
    int *ans;

    ans = (int *)malloc(*returnSize * sizeof(int));

    int c = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            ans[i] = nums[c++];
        } else {
            ans[i] = nums[n++];
        }
    }

    return ans;
}
