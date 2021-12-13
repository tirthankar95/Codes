class Solution {
public:
    int maxPower(string s) {
        int lb=0,ub=0,n=s.length(),res=1;
        while(ub<n)
        {
            if(s[lb]==s[ub])ub++;
            else{
                res=max(res,ub-lb);
                lb=ub;
            }
        }
        res=max(res,n-lb);
        return res;
    }
};