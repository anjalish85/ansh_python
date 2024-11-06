class Solution {
public:
    
    void solve(vector <int> arr, int idx, vector <vector <int>> &temp, vector <int> &subset, int target){
        int currentsum=accumulate(subset.begin(), subset.end(),0);
        
        if (currentsum==target){
            temp.push_back(subset);
            return;
        }
        
        if (currentsum > target){
            return;
        }
        
        for (int i=0; i<arr.size(); i++){
            subset.push_back(arr[i]);
            solve(arr, i + 1, temp, subset, target);
            subset.pop_back();  // Backtrack
        }
        
       
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector <vector <int>> temp;
        vector <int> subset;
        solve(candidates, 0, temp, subset, target);
                
        for (auto &t: temp){
            sort(t.begin(), t.end());
        }
        sort(temp.begin(), temp.end());
        
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        return temp;
    }
};