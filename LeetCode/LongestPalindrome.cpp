const int mxSize=256;
int hMap[mxSize];

class Solution {
public:
    int longestPalindrome(string s) {
        memset(hMap,0,sizeof(int)*mxSize);
        int n=s.length();
        for(int i=0;i<n;i++)hMap[(int)(s[i])]++;
        int ans=0,mxOdd=0;
        for(int i=0;i<256;i++)
        {
            if(hMap[i]!=0)
            {
                if(hMap[i]%2==0)ans+=hMap[i];
                else{
                    ans+=hMap[i]-1;
                    mxOdd=1;
                }
            }
        }
        if(mxOdd==1)ans++;
        return ans;
    }
};