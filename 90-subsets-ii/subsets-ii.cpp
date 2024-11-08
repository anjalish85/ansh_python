class Solution {
public:

void solve(int idx, vector <int> nums, vector <int> temp, vector<vector<int>> &ds){
    if (idx==nums.size()){
        ds.push_back(temp); return;
    }

    temp.push_back(nums[idx]);  
    solve(idx+1, nums, temp, ds);  
    temp.pop_back();

    while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
        idx++;
    }
    solve(idx+1, nums, temp, ds);    
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector <int> temp;
        vector<vector<int>> ds;

        solve(0, nums, temp, ds);

        return ds;
    }
};