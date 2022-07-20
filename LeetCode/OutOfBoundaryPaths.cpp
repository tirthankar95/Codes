typedef long long ll;
const int MOD=1e9+7;
const int mxSize=51;
ll dp[mxSize][mxSize][mxSize];

static int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
class Solution {
    void init(int r,int c,int move){
        for(int i=1;i<=move;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++)
                    dp[i][j][k]=0;
            }
        }
    }
public:
    int findPaths(int r, int c, int maxMove, int startRow, int startColumn) {
        init(r,c,maxMove);
        int in,jn;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<4;k++)
                {
                    in=i+dir[k][0];
                    jn=j+dir[k][1];
                    if(in<0 || jn<0 || in>=r || jn>=c)
                        dp[1][i][j]+=1;
                }//for-k.
            }//for-j.
        }//for-i.
        for(int k=2;k<=maxMove;k++){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                {
                    for(int l=0;l<4;l++)
                    {
                        in=i+dir[l][0];
                        jn=j+dir[l][1];
                        if(!(in<0 || jn<0 || in>=r || jn>=c))
                            dp[k][i][j]=(dp[k][i][j]+dp[k-1][in][jn])%MOD;
                    }//for-l.
                }//for-k.
            }//for-j.
        }//for-i.
        ll res=0;
        for(int i=1;i<=maxMove;i++)res=(res+dp[i][startRow][startColumn])%MOD;
        return res;
    }
};