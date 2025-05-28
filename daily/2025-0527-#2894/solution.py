class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1 = num2 = 0
        for num in range(1,n+1):
            if num % m != 0:
                num1 += num
            else:
                num2 += num
        return num1 - num2


class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        multiple = 0
        num2 = 0
        while multiple + m <= n:
            multiple += m
            num2 += multiple
        num1 = (1 + n) * n // 2 - num2
        return num1 - num2
