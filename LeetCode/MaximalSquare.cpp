const int mxSize=301;
int dpH[mxSize][mxSize];
int dpV[mxSize][mxSize];
int dp[mxSize][mxSize];

class Solution {
    int r,c;
    void print(){
        cout<<"H\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<dpH[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        cout<<"V\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<dpV[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;       
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        r=matrix.size();
        c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='1')
                {
                    dpH[i][j]=((j-1>=0)?dpH[i][j-1]:0)+1;
                    dpV[i][j]=((i-1>=0)?dpV[i-1][j]:0)+1;
                }
                else
                {
                    dpH[i][j]=0;
                    dpV[i][j]=0;
                }
            }//end of inner-for.
        }//end of outer-for.
        //print();
        int mxDim=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dp[i][j]=min(dpH[i][j],dpV[i][j]);
                if(i-1>=0 && j-1>=0)
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
                mxDim=max(mxDim,dp[i][j]);
            }//end of inner-for.
        }//end of outer-for. 
        return mxDim*mxDim;
    }
};