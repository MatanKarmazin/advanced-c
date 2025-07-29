#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                returnSize = (int*)malloc(2*sizeof(int));
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }
    }

    return 0;
}