int pivotIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int SumL = 0, SumR = 0;
        int L = i, R = i;

        if (i == 0) {
            SumL = 0;
        } else {
            while (L > 0) {
                L--;
                SumL += nums[L];
            }
        }

        if (i == numsSize - 1) {
            SumR = 0;
        } else {
            while (R < numsSize - 1) {
                R++;
                SumR += nums[R];
            }
        }

        if (SumL == SumR)
            return i;
    }

    return -1;
}