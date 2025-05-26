/**
 * Brute Force
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

/**
 * One pass hashmap
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *rets = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // find min and max (for the hashmap)
    int *hash;
    int min = nums[0], max = nums[0], hashSize = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min)  min = nums[i];
        if (nums[i] > max)  max = nums[i];
    }
    // create the hashmap
    hashSize = max - min + 1;
    hash = (int*)calloc(hashSize, sizeof(int));
    // the index zero should be confused with 'not exist'
    hash[nums[0] - min] = -1;
    // fill in the value for the hashmap
    for (int i = 1; i < numsSize; i++) {
        int find = target - nums[i];
        int findIndex = find - min;
        
        if (findIndex >= hashSize || findIndex < 0) {
            continue;
        } else if (hash[findIndex]) {
            rets[0] = i;
            rets[1] = (hash[findIndex] == -1) ? 0 : hash[findIndex];
            break;
        } else {
            hash[nums[i] - min] = i;
        }
    }

    return rets;
}

/*
 * link: https://leetcode.com/problems/two-sum/
 */
