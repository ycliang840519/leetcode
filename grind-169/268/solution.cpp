class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto sum = reduce(nums.begin(), nums.end());
        auto mth = ((1 + nums.size()) * nums.size()) / 2;
        return mth - sum;
    }
};
