//#define DBG
const int mxSize1=6e2+1;
const int mxSize2=1e2+1;
int dp[mxSize1][mxSize2][mxSize2];

class Solution {
    void init(int a,int b,int c){
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                for(int k=0;k<=c;k++)
                    dp[i][j][k]=0;
            }
        }//
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dim0=strs.size();
        int dim1=m; // zeros.
        int dim2=n; // ones.
        init(dim0,dim1,dim2);
        int ones,zeros;
        for(int i=0;i<dim0;i++){
            zeros=0;
            for(int j=0;j<strs[i].length();j++)
                if(strs[i][j]=='0')zeros++;
            ones=strs[i].length()-zeros;
            for(int j0=0;j0<=dim1;j0++)
            {
                for(int j1=0;j1<=dim2;j1++)
                {
                    if(zeros<=j0 && ones<=j1)
                        dp[i+1][j0][j1]=max(dp[i][j0][j1],1+dp[i][j0-zeros][j1-ones]);
                    else 
                        dp[i+1][j0][j1]=dp[i][j0][j1];
                }
            }//end of js.
        }//end of i.
#ifdef DBG
        for(int i=0;i<=dim0;i++){
            for(int j=0;j<=dim1;j++){
                for(int k=0;k<=dim2;k++)
                    cout<<dp[i][j][k]<<" ";
                cout<<endl;
            }
            cout<<endl;
        }//
        cout<<endl;
#endif
        return dp[dim0][dim1][dim2];
    }
};