class Solution {
public:
    int fn(int k) {
        // Calculate factorial
        if (k == 0 || k == 1) {
            return 1;
        }
        int result = 1;
        for (int i = 2; i <= k; ++i) {
            result *= i;
        }
        return result;
    }

    void valueadd(int k, int n, vector<int>& arr, string& s) {
        if (n == 0) return;

        int fact = fn(n - 1); // (n-1)! to determine the index
        int index = (k - 1) / fact;  // Determine the index to pick in this step

        s += to_string(arr[index]); // Add the number at the index to the result string
        arr.erase(arr.begin() + index); // Remove that number from the list

        k -= index * fact;  // Reduce k to get the kth position within the remaining options

        valueadd(k, n - 1, arr, s); // Recurse for the next position
    }

    string getPermutation(int n, int k) {
        vector<int> arr;
        string s;

        // Populate arr with numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            arr.push_back(i);
        }

        valueadd(k, n, arr, s); // Start generating the permutation

        return s;
    }
};