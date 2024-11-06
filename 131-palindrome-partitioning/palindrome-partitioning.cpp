class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Recursive function to generate the partitions
    void solve(string &s, int idx, vector<string> &temp, vector<vector<string>> &ans) {
        // Base case: if we've reached the end of the string, add the current partition
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        // Try all possible substrings starting from idx
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                // Add palindrome substring to current partition
                temp.push_back(s.substr(idx, i - idx + 1));
                // Recurse with the next substring
                solve(s, i + 1, temp, ans);
                // Backtrack and remove the last added substring
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};
