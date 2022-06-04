class Solution {
    int R,C;
    vector<vector<char>> board;
    vector<vector<string>> sol;
    string __blank__;
    bool isValid(int r,int c){
        int cnt=0;
        for(int i=0;i<R;i++)
            if(board[i][c]=='Q')cnt++;
        if(cnt>1)return false;
        int mi=min(r,c);
        int i=r-mi;int j=c-mi;
        cnt=0;
        while(i<R && j<C)
            if(board[i++][j++]=='Q')cnt++;
        if(cnt>1)return false;
        cnt=0;
        mi=min(R-r-1,c);
        i=r+mi;j=c-mi;
        while(i>=0 && j<C)
            if(board[i--][j++]=='Q')cnt++;
        if(cnt>1)return false;
        return true;
    }
    void fn(int row){
        if(row==R){
            vector<string> oneSol(R,__blank__);
            for(int i=0;i<R;i++)
                for(int j=0;j<C;j++)
                    oneSol[i][j]=board[i][j];
            sol.push_back(oneSol);
            return;
        }
        for(int j=0;j<C;j++){
            board[row][j]='Q';
            if(isValid(row,j))
                fn(row+1);
            board[row][j]='.';
        }//end of for.         
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        R=n;C=n;
        vector<vector<char>> dummyBoard(R,vector<char>(C,'.'));
        board=dummyBoard;
        sol.clear();
        string _blank_(n,'.');
        __blank__=_blank_;
        fn(0);
        return sol;        
    }
};