class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallestTillNow = nums[0];
        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > smallestTillNow)
                ans = max(nums[i] - smallestTillNow, ans);
            smallestTillNow = min(nums[i], smallestTillNow);
        }
        return ans;
    }
};
