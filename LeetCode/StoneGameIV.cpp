const int mxSize1=1e5+1;
const int mxSize2=1e3+1;
bool dp[mxSize1][2];
int pS[mxSize2];
bool isFirst=true;

class Solution {
    void init(){
        int iter=0;
        for(int i=1;i*i<mxSize1;i++)
            pS[iter++]=i*i;
        for(int i=1;i<mxSize1;i++){
            for(int j=0;j<mxSize2 && pS[j]<=i;j++)
                dp[i][0]|=(bool)(1-dp[i-pS[j]][1]);
            dp[i][1]=dp[i][0];
        }
    }
public:
    bool winnerSquareGame(int n) {
        if(isFirst){
            isFirst=false;
            init();
        }
        return dp[n][0];
    }
};