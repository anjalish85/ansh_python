class Solution {
public:
void solve(int idx,  vector <int> nums, vector < vector <int>> &ds,  vector <int> temp){
    if (idx==nums.size()){
        ds.push_back(temp);
        return;
    }
    
    temp.push_back(nums[idx]);
    solve(idx+1, nums, ds, temp );
    temp.pop_back();
    while (idx+1<nums.size() && nums[idx]==nums[idx+1]){
        idx++;
    }
    solve(idx+1, nums, ds, temp );
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector < vector <int>> ds;
        vector <int> temp;
        sort(nums.begin(), nums.end());

        solve (0, nums, ds, temp);
        return ds;
    }
};