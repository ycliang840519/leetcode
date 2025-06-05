int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1, ans = -1;
    while (r >= l) {
        int m = (l + r) / 2;
        if (target > nums[m]) {
            l = m + 1;
        } else if (target < nums[m]) {
            r = m - 1;
        } else if (target == nums[m]){
            ans = m;
            break;
        }
    }
    return ans;
}
