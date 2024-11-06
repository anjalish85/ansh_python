class Solution {
public:
    
    void solve(int idx, vector<int>& arr, int target, vector<int> temp,vector <vector<int> >& ds){
        if (idx==arr.size()){
            if ( target==0){
                ds.push_back(temp);
                 
            }
            return;  
        }
        
        if (arr[idx]<=target){
            temp.push_back(arr[idx]);
            solve(idx, arr, target-arr[idx], temp, ds);
            temp.pop_back();
        }
        
        solve(idx+1, arr, target, temp, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <int> temp;
        vector <vector<int>> ds;
        
        solve(0, candidates, target, temp, ds);
        
        return ds;
    }
};