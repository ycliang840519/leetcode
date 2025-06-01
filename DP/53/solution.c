/* Kadane's algorithm */
int maxSubArray(int* nums, int numsSize) {
    int dp[100001] = {}, max = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = nums[i] > dp[i-1] + nums[i] ? nums[i] : dp[i-1] + nums[i];
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}

int maxSubArray(int* nums, int numsSize) {
    int dp = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (dp < 0)
            dp = nums[i];
        else
            dp = nums[i] + dp;

        if (dp > max)
            max = dp;
    }
    return max;
}
