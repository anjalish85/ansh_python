class Solution:
    def arraySign(self, nums: List[int]) -> int:
        c=0
        if 0 in nums:
            return 0
        for i in nums:
            if i<0:
                c=c+1
        if c%2==0 :
            return 1
        return -1
            