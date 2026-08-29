int dominantIndex(int* nums, int numsSize) {
    int greaterIndex;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            greaterIndex = i;
        } else if (nums[i] > nums[greaterIndex]) {
            greaterIndex = i;
        }
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != nums[greaterIndex]) {
            if (nums[greaterIndex] < (nums[i] * 2))
                return -1;
        }
    }
    
    return greaterIndex;
}