class Solution {
public:
    bool pal(string s, int st, int end){
        while (st<end){
            if (s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    
    void solve(vector <vector<string>> &ds, vector <string> t, string s, int idx){
        if (idx==s.size()){
            ds.push_back(t);
            return;
        }
        for (int i=idx; i<s.size(); i++){
            if (pal(s, idx, i)){
                t.push_back(s.substr(idx, i-idx+1));
                solve(ds, t, s, i+1);
                t.pop_back();
            }
        }       
    }
    
    vector<vector<string>> partition(string s) {
        
        vector <vector<string>> ds;
        vector <string> t;
        
        solve(ds, t, s, 0);
        
        return ds;
    }
};