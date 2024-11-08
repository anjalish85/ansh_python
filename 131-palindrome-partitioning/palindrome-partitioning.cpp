class Solution {
public:

bool pal(string str, int s, int e){
    while(s<e){
        if (str[s]!=str[e]){
            return false;
        }
        s++;e--;
    }
    return true;
}

void solve(int idx, string s, vector<vector<string>>& ds,  vector<string> temp ){
    if (idx==s.size()){
        ds.push_back(temp);
        return;
    }

    for (int i=idx; i<s.size(); i++){
        if (pal(s, idx, i)){
            temp.push_back(s.substr(idx, i-idx+1));
            solve(i+1, s, ds, temp);
            temp.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ds;
        vector<string> temp;

        solve(0, s, ds, temp );

        return ds;
    }
};