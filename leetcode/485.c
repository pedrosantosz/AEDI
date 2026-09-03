int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int seq = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1)
            seq++;
        else
            seq = 0;
        
        if (seq > max)
            max = seq;
    }

    return max;
}