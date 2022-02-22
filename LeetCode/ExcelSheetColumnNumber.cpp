typedef long long ll;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int lb=(int)('A')-1;
        ll pow26=1;ll res=0;
        for(int i=n-1;i>=0;i--){
            res+=pow26*(columnTitle[i]-lb);
            pow26*=26;
        }//end of for. 
        return (int)res;
    }
};