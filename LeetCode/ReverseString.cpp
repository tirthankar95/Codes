class Solution {
public:
    void reverseString(vector<char>& s) {
        int lb=0;int ub=s.size()-1;
        while(lb<=ub)
            swap(s[lb++],s[ub--]);
    }
};