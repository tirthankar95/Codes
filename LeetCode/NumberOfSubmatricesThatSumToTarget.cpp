//#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxSize=1e2+1;
int sum[mxSize][mxSize];

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            sum[i][0]=matrix[i][0];
            for(int j=1;j<c;j++)
                sum[i][j]=sum[i][j-1]+matrix[i][j];
        }//end-i.
        for(int j=0;j<c;j++){
            for(int i=1;i<r;i++)
                sum[i][j]=sum[i-1][j]+sum[i][j];
        }//end-j.
        int cnt=0,temp,a,b,common;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int i_=0;i_<=i;i_++){
                    for(int j_=0;j_<=j;j_++){
                        a=(j_-1<0)?0:sum[i][j_-1];
                        b=(i_-1<0)?0:sum[i_-1][j];
                        common=(i_-1<0 || j_-1<0)?0:sum[i_-1][j_-1];
                        temp=sum[i][j]-a-b+common;
                        if(temp==target)cnt++;
                    }
                }//inner
            }
        }//outer
        return cnt;
    }
};