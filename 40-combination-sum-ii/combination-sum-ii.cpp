class Solution {
public:
    void solve(vector<int>& arr, int target, int idx, vector<vector<int>>& ds, vector<int>& temp) {
        if (target == 0) {
            ds.push_back(temp);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            // Skip duplicates by checking the previous element
            if (i > idx && arr[i] == arr[i - 1]) continue; // Skip if duplicate

            // If current element is greater than the target, no need to proceed further
            if (arr[i] > target) break;

            // Choose the current element
            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i + 1, ds, temp); // Move to next element (i + 1)
            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> temp;

        // Sort the array to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0, ds, temp);

        return ds;
    }
};
