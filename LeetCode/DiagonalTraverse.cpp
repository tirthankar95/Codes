class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        vector<int> sol(r*c);
        if(r==1)
        {
            for(int i=0;i<c;i++)
                sol[i]=mat[0][i];
            return sol;
        }
        if(c==1)
        {
            for(int i=0;i<r;i++)
                sol[i]=mat[i][0];
            return sol;            
        }
        int iter=0,i,j;
        sol[iter++]=mat[0][0];
        i=0,j=1;
        while(i<r && j<c)
        {
            //////////////////////////
            while(i<r && j>=0)
            {
                sol[iter++]=mat[i][j];
                i+=1;
                j-=1;
            }
            i-=1,j+=1;
            if(i>=r-1)
                i=r-1,j+=1;
            else 
                i+=1;
            //////////////////////////
            cout<<i<<" "<<j<<endl;
            while(i>=0 && j<c)
            {
                sol[iter++]=mat[i][j];
                i-=1;
                j+=1;
            }
            i+=1,j-=1;
            if(j>=c-1)
                i+=1,j=c-1;
            else 
                j+=1;
            //////////////////////////
        }
        return sol;
    }
};