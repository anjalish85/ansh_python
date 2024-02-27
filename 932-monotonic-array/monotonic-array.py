class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        monotonic = True
        monotonic1 = True
        
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                monotonic = False
        
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                monotonic1 = False
        
        if monotonic:
            return monotonic
        elif monotonic1:
            return monotonic1
        else:
            return False