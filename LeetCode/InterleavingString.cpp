class Solution {
    int n1,n2,n3;
    bool fn(string s1,int i1,string s2,int i2,string s3,int i3){
        if(i3==n3 && i2==n2 && i1==n1)
            return true;
        bool res=false;
        if(i2<n2 && s3[i3]==s2[i2]){
            res=fn(s1,i1,s2,i2+1,s3,i3+1);
        }
        if(i1<n1 && s3[i3]==s1[i1]){
            res|=fn(s1,i1+1,s2,i2,s3,i3+1);
        }
        return res;        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n1+n2!=n3)
            return false;
        return fn(s1,0,s2,0,s3,0);
    }
};
//#define DBG
const int mxSize1=101;
bool dp[mxSize1][mxSize1];

class Solution {
#ifdef DBG
    void print(int n1,int n2){
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
#endif
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length(),i;
        if(n1+n2!=n3)return false;
        for(int i1=0;i1<=n1;i1++)
            for(int i2=0;i2<=n2;i2++)
                dp[i1][i2]=false;
        dp[0][0]=true;
        for(int i1=0;i1<=n1;i1++){
            for(int i2=0;i2<=n2;i2++){
                i=i1+i2;
                if(i1-1>=0 && s3[i-1]==s1[i1-1]){
                    dp[i1][i2]|=dp[i1-1][i2];
                }
                if(i2-1>=0 && s3[i-1]==s2[i2-1])
                    dp[i1][i2]|=dp[i1][i2-1];
            }
        }
#ifdef DBG
        print(n1,n2);
#endif
        return dp[n1][n2];
    }
};