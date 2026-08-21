// 1480. Running Sum of 1d Array

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int sum = 0;
    *returnSize = numsSize;

    int *array = (int *) malloc(sizeof(int) * (*returnSize));

    for (int i = 0; i < *returnSize; i++) {
        sum += nums[i];
        array[i] = sum;
    }

    return array;
}