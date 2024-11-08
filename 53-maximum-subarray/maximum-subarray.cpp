class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r=nums[0]; int m=nums[0];

        for (int i=1; i<nums.size(); i++){
            r=max(r+nums[i], nums[i]);
            m=max(r,m);
        }

        return m;

    }
};