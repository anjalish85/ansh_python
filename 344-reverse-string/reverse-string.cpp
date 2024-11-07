class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=s.size()-1;
        int st=0;
        while (st<l){
            swap(s[st++], s[l--]);
        }
    }
};