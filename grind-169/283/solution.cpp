class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int moveIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if nums[i] is not zero, store nums[i] to where it should be (starting from 0)
            if (nums[i] != 0) {
                swap(nums[i], nums[moveIndex++]);
            }
        }
    }
};
