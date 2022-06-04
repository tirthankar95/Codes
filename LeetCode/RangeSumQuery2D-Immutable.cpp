//#define DBG

class NumMatrix {
    int r,c;
    vector<vector<int>> m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        r=matrix.size();
        c=matrix[0].size();
        m.resize(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                m[i][j]=matrix[i][j]+((i-1>=0)?m[i-1][j]:0)+((j-1>=0)?m[i][j-1]:0)-((i-1>=0 && j-1>=0)?m[i-1][j-1]:0);
            }
        }//end of outer-i. 
#ifdef DBG
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cout<<m[i][j]<<" ";
            cout<<endl;
        }
#endif
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=m[row2][col2];
        sum-=(row1-1>=0)?m[row1-1][col2]:0;
        sum-=(col1-1>=0)?m[row2][col1-1]:0;
        sum+=(row1-1>=0 && col1-1>=0)?m[row1-1][col1-1]:0;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */