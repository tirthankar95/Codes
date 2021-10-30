typedef vector<vector<bool>> vvb;
class Solution {
    int R,C;
    int M(char ch){return (int)(ch-'0');}
    void verify(vector<vector<char>>& board)
    {
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    bool presInSubGrid(vector<vector<char>>& board,int i,int j,int element)
    {
        char ch=(char)('0'+element);
        int grid_i=(i/3)*3;
        int grid_j=(j/3)*3;
        //cout<<i<<" "<<j<<" "<<grid_i<<" "<<grid_j<<endl;
        for(int io=0;io<3;io++)
        {
            for(int jo=0;jo<3;jo++)
            {
                if(ch==board[grid_i+io][grid_j+jo])
                    return true;
            }
        }
        return false;
    }
public:
    bool btrack(vector<vector<char>>& board,int i,int j,vvb& rowMap,vvb& colMap)
    {
        if(i>=R)return true;
        int in=i;int jn=j+1;
        if(jn>=C){
            in=i+1;
            jn=0;
        }
        if(board[i][j]=='.'){
            for(int it=1;it<=9;it++)
            {
                if(!rowMap[i][it] && !colMap[j][it] && !presInSubGrid(board,i,j,it))
                {
                    rowMap[i][it]=true;
                    colMap[j][it]=true;
                    board[i][j]=(char)('0'+it);
                    if(btrack(board,in,jn,rowMap,colMap))
                        return true;
                    rowMap[i][it]=false;
                    colMap[j][it]=false;
                    board[i][j]='.';
                }
            }//end of for.
        }//end of if.
        else if(btrack(board,in,jn,rowMap,colMap))return true;
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        R=board.size();
        C=board[0].size();
        vvb rowMap(R,vector<bool>(10,false));
        vvb colMap(C,vector<bool>(10,false));
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(board[i][j]=='.')continue;
                rowMap[i][M(board[i][j])]=true;
                colMap[j][M(board[i][j])]=true;
            }
        }
        btrack(board,0,0,rowMap,colMap);
        //verify(board);
    }
};