int findMax(int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return a;
    } else {
        if (b > c)
            return b;
    }
    return c;
}

int findMin(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
    } else {
        if (b < c)
            return b;
    }
    return c;
}

int maxProduct(int* nums, int numsSize) {
    int max[20001] = {}, min[20001] = {}, ans = nums[0];
    max[0] = min[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min[i] = findMin(nums[i], min[i-1]*nums[i], max[i-1]*nums[i]);
        max[i] = findMax(nums[i], max[i-1]*nums[i], min[i-1]*nums[i]);
        if (max[i] > ans)
            ans = max[i];
    }
    return ans;
}

/* less memory used */

int findMax(int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return a;
    } else {
        if (b > c)
            return b;
    }
    return c;
}

int findMin(int a, int b, int c) {
    if (a < b) {
        if (a < c)
            return a;
    } else {
        if (b < c)
            return b;
    }
    return c;
}

int maxProduct(int* nums, int numsSize) {
    int ans, maxtmp, mintmp;
    ans = maxtmp = mintmp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int tmp = mintmp;
        mintmp = findMin(nums[i], mintmp*nums[i], maxtmp*nums[i]);
        maxtmp = findMax(nums[i], tmp*nums[i], maxtmp*nums[i]);
        if (maxtmp > ans)
            ans = maxtmp;
    }
    return ans;
}
