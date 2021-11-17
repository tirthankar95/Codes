class Solution {
public:
    int uniquePaths(int R, int C) {
        vector<vector<int>> dist(R,vector<int>(C,0));
        dist[0][0]=1;
        int a,b;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                a=(i-1<0)?0:dist[i-1][j];
                b=(j-1<0)?0:dist[i][j-1];
                dist[i][j]+=(a+b);
            }//end of j.
        }//end of i.
        return dist[R-1][C-1];
    }
};