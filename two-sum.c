/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *rets = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int comp = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == comp) {
                rets[0] = i;
                rets[1] = j;
                break;
            }
        }
    }

    return rets;
}
