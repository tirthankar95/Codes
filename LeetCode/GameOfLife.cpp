const int mxN=8;
static int delta[mxN][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        int countOnes,i_,j_;
        vector<vector<int>> nextBoard(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                countOnes=0;
                for(int d=0;d<mxN;d++){
                    i_=i+delta[d][0];
                    j_=j+delta[d][1];
                    if(i_<0 || j_<0 || i_>=r || j_>=c)continue;
                    if(board[i_][j_])countOnes++;
                }
                if(countOnes<2)nextBoard[i][j]=0;
                else if(board[i][j] && (countOnes==2 || countOnes==3))nextBoard[i][j]=1;
                else if(board[i][j] && countOnes>3)nextBoard[i][j]=0;
                else if(!board[i][j] && countOnes==3)nextBoard[i][j]=1;
                else nextBoard[i][j]=board[i][j];
            }//end of outer-j.
        }//end of inner-i.
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                board[i][j]=nextBoard[i][j];
    }
};