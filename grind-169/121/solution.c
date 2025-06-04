/* for loop to find the smallest number til i th day, 
 * and findMax between (ith day's prices, maxProf).
 */

int findMax(int a, int b) {
    return ((a > b) ? a : b);
}

int findMin(int a, int b) {
    return ((a < b) ? a : b);
}

int maxProfit(int* prices, int pricesSize) {
    int currentMin = prices[0];
    int maxProf = 0;
    for (int i = 1; i < pricesSize; i++) {
        currentMin = findMin(currentMin, prices[i]);
        maxProf = findMax(maxProf, prices[i] - currentMin);
    }
    return maxProf;
}



/* DP: MaxSubarray of the profit array */

int findMax(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int maxProfit(int* prices, int pricesSize) {
    int maxSubarray[100001] = {};
    int delta[100001] = {};
    int ans = 0;
    for (int i = 1; i < pricesSize; i++) {
        delta[i] = prices[i] - prices[i-1];
        maxSubarray[i] = findMax(delta[i], maxSubarray[i-1] + delta[i]);
        if (maxSubarray[i] > ans)
            ans = maxSubarray[i];
    }
    return ans;
}
