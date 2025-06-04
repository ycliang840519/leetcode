#### TLE: List all the possible result and find Max ####

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max = 0
        for i in range(0, len(prices)):
            for j in range(i + 1, len(prices)):
                if (prices[j] - prices[i] > max):
                    max = prices[j] - prices[i]
        return max

#### Accepted
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProf = 0 
        minPrice = 10001
        for i in prices:
            minPrice = min(i, minPrice)
            maxProf = max(i - minPrice, maxProf)
        return maxProf
        

