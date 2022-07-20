//#define DBG
typedef long long ll;
const int MOD=1e9+7;
const int mxSize=1e3+1;
ll dp[mxSize][mxSize];

class Solution {
    int maxInv(int i){
        return i*(i+1)/2;
    }
public:
    int kInversePairs(int n, int k) {
        {//INIT
            for(int i=0;i<n;i++)
                for(int j=0;j<=k;j++)
                    dp[i][j]=0;
        }
        for(int i=0;i<n;i++){// i ~ (# of elements -1)
            for(int j=0;j<=min(k,maxInv(i));j++){// j ~ # of inversions.
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                for(int jc=0;jc<=min(j,i);jc++){// jc ~ first element of the inversion.
                    dp[i][j]=(dp[i][j]+dp[i-1][j-jc])%MOD;
                }//end-jc.
            }//end-j.
        }//end-i.
#ifdef DBG
        {//PRINT
            for(int i=0;i<n;i++){
                for(int j=0;j<=k;j++)
                    cout<<dp[i][j]<<" ";
                cout<<endl;
            }
        }
#endif
        return dp[n-1][k];
    }
};

// OPTIMIZED ~ After finding out the pattern.
//#define DBG
typedef long long ll;
const int MOD=1e9+7;
const int mxSize=1e3+1;
ll dp[mxSize][mxSize];

class Solution {
    int maxInv(int i){
        return i*(i+1)/2;
    }
public:
    int kInversePairs(int n, int k) {
        {//INIT
            for(int i=0;i<=n;i++)
                for(int j=0;j<=k;j++)
                    dp[i][j]=0;
        }
        int lb,ub,win=0;
        ll rSum;
        dp[0][0]=1;
        for(int i=1;i<=n;i++){// i ~ (# of elements)
            win++;
            lb=ub=rSum=0;
            for(int j=0;j<=min(k,maxInv(i-1));j++){// j ~ # of inversions.
                rSum=(rSum+dp[i-1][ub++])%MOD;
                if(ub-lb>win){
                    rSum=(rSum-dp[i-1][lb++])%MOD;
                    if(rSum<0)rSum+=MOD;
                }
                dp[i][j]=rSum;
            }//end-j.
        }//end-i.
#ifdef DBG
        {//PRINT
            for(int i=0;i<=n;i++){
                for(int j=0;j<=k;j++)
                    cout<<dp[i][j]<<" ";
                cout<<endl;
            }
        }
#endif
        return dp[n][k];
    }
};