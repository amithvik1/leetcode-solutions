class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        seen = {}
        for i in range(len(nums)):
            num = nums[i]
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i

