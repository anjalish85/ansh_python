class Solution {
public:
void solve(int idx, vector<int> nums, int target, vector <vector<int>>& ds, vector<int> t){
    if (idx==nums.size()){
        if (target==0){
            ds.push_back(t);
        }
        return;
    }

    if (nums[idx]<=target){
        t.push_back(nums[idx]);
        solve(idx+1, nums, target-nums[idx], ds, t);
        t.pop_back();
    }

    while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
        idx++;
    }

    solve(idx+1, nums, target, ds, t);   
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ds; 
        vector <int> t;

        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ds, t);

        return ds;
    }
};