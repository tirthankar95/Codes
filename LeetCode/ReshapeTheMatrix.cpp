class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int R=mat.size();
        int C=mat[0].size();
        if(R*C!=r*c)return mat;
        vector<vector<int>> res(r,vector<int>(c));
        int cnt=0;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                res[cnt/c][cnt%c]=mat[i][j];
                cnt++;
            }
        }
        return res;
    }
};