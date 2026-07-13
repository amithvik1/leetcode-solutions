class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        lsum = 0
        rsum = sum(nums)

        ans = []

        for x in nums:
            rsum -= x
            ans.append(abs(lsum-rsum))
            lsum += x
        return ans
