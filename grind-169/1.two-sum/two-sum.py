class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dct = {}
        for index, value in enumerate(nums):
            find = target - value
            if find in dct:
                return [dct[find], index]
            dct[value] = index
