class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ans = []
        son = nums[0]
        for x in range(len(nums)-1):
            ans.append(son)
            son += nums[x+1]
        ans.append(son)
        return ans
