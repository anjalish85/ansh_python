class Solution {
public:

void solve(int idx, int target, vector <int> nums, vector<vector<int>> & ds, vector<int> temp){
    if (idx==nums.size()){
        if (target==0){
            ds.push_back(temp);
        }
        return ;
    }

    if (nums[idx]<=target){
        temp.push_back(nums[idx]);
        solve(idx, target-nums[idx], nums, ds, temp);
        temp.pop_back();
    }

    solve(idx+1, target, nums, ds, temp);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> temp;

        solve(0, target, candidates, ds, temp);

        return ds;
    }
};