typedef long long ll;
const int MOD=2e9+1;
const int mxSize=100;
ll dp[mxSize][mxSize];
bool first=true;

class Solution {
    void init(){
        ll var0,var1;
        for(int i=0;i<mxSize;i++){
            for(int j=0;j<mxSize;j++){
                dp[i][j]=0;
                var0=(i-1>=0)?dp[i-1][j]:0;
                var1=(j-1>=0)?dp[i][j-1]:0;
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=(var0+var1)%MOD;
            }
        }
    }
public:
    int uniquePaths(int m, int n) {
        if(first){
            first=false;
            init();
        }
        return dp[m-1][n-1];
    }
};