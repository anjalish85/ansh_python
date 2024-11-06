class Solution {
public:
    void solve(int idx, vector<int>& arr, int target, vector<vector<int>>& ds, vector<int>& temp) {
        if (idx == arr.size()) {
            if (target == 0) {
                ds.push_back(temp);
            }
            return;
        }

        // Include the element if it's not greater than the target
        if (arr[idx] <= target) {
            temp.push_back(arr[idx]);
            solve(idx, arr, target - arr[idx], ds, temp); // Pass `idx` again to allow reuse
            temp.pop_back(); // Backtrack
        }

        // Exclude the element and move to the next index
        solve(idx + 1, arr, target, ds, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> temp;
        solve(0, candidates, target, ds, temp);
        return ds;
    }
};
