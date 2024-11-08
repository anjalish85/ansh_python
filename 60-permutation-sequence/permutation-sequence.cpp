class Solution {
public:
    
    string getPermutation(int n, int k) {
        
        vector <int> num;
        for (int i=1; i<=n; i++){
            num.push_back(i);
        }
        string s="";
        for (int i=0; i<n; i++){
            s+=to_string(num[i]);
        }

        for (int i=1; i<k; i++){
            next_permutation(s.begin(), s.end());
        }

        return s;
    }

};