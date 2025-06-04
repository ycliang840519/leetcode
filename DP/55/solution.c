/* DP: TLE */

bool canJump(int* nums, int numsSize) {
    int dp[10001] = {};  // if index i is reachable, dp[i] == 1
    dp[0] = 1;
    for(int i = 0; i < numsSize; i++) {
        if(dp[i] == 1)
            for(int j = 1; j <= nums[i]; j++)
                if(i + j <= 10000)
                    dp[i + j] = 1;
    }
    return dp[numsSize - 1] == 1;
}

/* Greedy */
bool canJump(int* nums, int numsSize) {
    int maxReach = 0;
    for (int i = 0; i < numsSize; i++) {
        if (maxReach < i)
            return false;
        if (nums[i] + i > maxReach)
            maxReach = nums[i] + i;
        if(maxReach >= numsSize - 1)
            return true;
    }
    return false;
}
