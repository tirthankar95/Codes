static int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
    int r,c;
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        int i_,j_;
        board[i][j]='U';
        for(int delta=0;delta<4;delta++)
        {
            i_=i+dir[delta][0];
            j_=j+dir[delta][1];
            if(i_<0 || j_<0 || i_>=r || j_>=c || board[i_][j_]!='O')
                continue;
            dfs(board,i_,j_);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        r=board.size();
        c=board[0].size();
        for(int i=0;i<r;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][c-1]=='O')
                dfs(board,i,c-1);
        }//end of for-j.
        for(int j=0;j<c;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[r-1][j]=='O')
                dfs(board,r-1,j);
        }//end of for-j.
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
            }//end of for-j.
        }//end of for-i.
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='U')
                    board[i][j]='O';
            }//end of for-j.
        }//end of for-i.
    }
};