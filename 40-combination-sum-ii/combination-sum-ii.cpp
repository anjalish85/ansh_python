class Solution {
public:
    void solve(int idx, vector<int>& arr, int target, vector<vector<int>>& ds, vector<int>& temp) {
            if (target == 0) {
                ds.push_back(temp);return;
            }
        
            for (int i=idx; i<arr.size(); i++){
                if (i > idx && arr[i]==arr[i-1]) continue;
                if (arr[i] > target) break;
            
                temp.push_back(arr[i]);
                solve(i+1, arr, target - arr[i], ds, temp); // Pass `idx` again to
                temp.pop_back(); 
            }
        
        //solve(idx+1, arr, target , ds, temp);
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ds;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ds, temp);
        return ds;
    }
};
