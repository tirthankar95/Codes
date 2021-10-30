typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=0,c=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vi sol(n*m);
        if(n==1)return matrix[0];
        if(m==1)
        {
            for(int i=0;i<n;i++)sol[i]=matrix[i][0];
            return sol;
        }
        int ptr=0,offset=0;
        bool isSquare=(n==m)?true:false;
        int n_orig=min(n,m);
        while((!isSquare && offset<n_orig/2)||(isSquare && offset<=n_orig/2))
        {
            while(c<m)sol[ptr++]=matrix[r][c++];
            c=m-1,r=offset+1;
            
            while(r<n)sol[ptr++]=matrix[r++][c];
            r=n-1;
            m--;c=m-1;

            while(c>=offset)sol[ptr++]=matrix[r][c--];
            c=offset;
            n--;r=n-1;
            offset++;
            
            while(r>=offset)sol[ptr++]=matrix[r--][c];
            r=offset,c=offset;
        }
        if(r<n && m>n)
        {
            while(c<m)
                sol[ptr++]=matrix[r][c++];
        }
        else if(c<m)
        {
            while(r<n)
                sol[ptr++]=matrix[r++][c];
        }
        return sol;
    }
};