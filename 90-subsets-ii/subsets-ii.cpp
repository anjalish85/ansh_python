#include <vector>
#include <algorithm>

class Solution {
public:
    void solve(std::vector<int>& arr, int idx, std::vector<int>& subset, std::vector<std::vector<int>>& temp) {
        if (idx == arr.size()) {
            temp.push_back(subset);
            return;
        }
        
        // Include the current element
        subset.push_back(arr[idx]);
        solve(arr, idx + 1, subset, temp);
        subset.pop_back();  // Backtrack
        
        // Exclude the current element, but skip duplicates
        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) {
            idx++;  // Skip duplicates
        }
        solve(arr, idx + 1, subset, temp);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());  // Sort to ensure duplicates are adjacent
        
        std::vector<std::vector<int>> temp;
        std::vector<int> subset;
        
        solve(nums, 0, subset, temp);
        
        return temp;
    }
};
