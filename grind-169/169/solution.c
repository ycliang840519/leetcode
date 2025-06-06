// https://ithelp.ithome.com.tw/articles/10213285
// Boyer–Moore majority vote algorithm

int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int ans = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (ans == nums[i]) {
            count++;
        } else if (count > 0) {
            count--;
        } else {
            ans = nums[i];
            count = 1;
        }
    }
    return ans;
}
