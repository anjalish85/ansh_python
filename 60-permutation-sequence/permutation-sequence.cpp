class Solution {
public:
    
    int fn(int n){
        if (n==0 || n==1){
            return 1;
        }
        return n*fn(n-1);
    }
    
    void valueadd(int k, int n, vector <int>  arr, string &s){
        if (n==0) return;
        
        int idx=(k-1)/fn(n-1);
        
        s+=to_string(arr[idx]);
        arr.erase(arr.begin()+idx);
        k=k-idx*fn(n-1);
        
        valueadd(k, n - 1, arr, s); 
        
    }
    string getPermutation(int n, int k) {
        
        vector <int> num;
        for(int i=1; i<=n; i++){
            num.push_back(i);
        }
        string t;
        
        valueadd(k, n , num, t);
        return t;
    }
};