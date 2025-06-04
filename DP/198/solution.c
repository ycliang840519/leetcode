int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize) {
    int dp[101] = {};
    if (numsSize < 2)   return nums[0];
    dp[0] = nums[0];
    dp[1] = findMax(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        dp[i] = findMax(dp[i-2] + nums[i], dp[i-1]);
    }
    return dp[numsSize - 1];
}
