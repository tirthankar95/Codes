class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> sol(n,vector<int>(n));
        int is=0,js=0;
        int in=n-1,jn=n-1;
        int count=1;
        while(is<=in || js<=jn)
        {
            for(int j=js;j<=jn;j++)
                sol[is][j]=count++;
            is++;
            for(int i=is;i<=in;i++)
                sol[i][jn]=count++;
            jn--;
            for(int j=jn;j>=js;j--)
                sol[in][j]=count++;
            in--;
            for(int i=in;i>=is;i--)
                sol[i][js]=count++;
            js++;
        }//end of while. 
        return sol;    
    }
};