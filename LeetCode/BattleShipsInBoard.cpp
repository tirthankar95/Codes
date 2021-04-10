int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

class Solution {
    int cnt,r,c;
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        board[i][j]='@';
        int deli,delj;
        for(int iter=0;iter<4;iter++)
        {
            deli=i+dir[iter][0];
            delj=j+dir[iter][1];
            if(deli>=0 && delj>=0 && deli<r && delj<c && board[deli][delj]=='X')
                dfs(deli,delj,board);
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        r=board.size();
        c=board[0].size();
        cnt=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='X')
                    cnt++,dfs(i,j,board);
            }
        }//end of outer for.
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(board[i][j]=='@')board[i][j]='X';
        return cnt;
    }
};
/*
int countBattleships(vector<vector<char>>& board) {
        int answer=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    if((i && board[i-1][j]=='X') || (j && board[i][j-1]=='X')){
                        continue;
                    }
                    else ++answer;
                }
            }
        }
        return answer;
    }
*/