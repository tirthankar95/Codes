const int mxSize=201;
int grid[mxSize][mxSize];

class Solution {
    int r,c;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        r=matrix.size();
        if(r==0)return 0;
        c=matrix[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                grid[i][j]=(int)(matrix[i][j]-'0');
        }
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j])
                    grid[i][j]+=grid[i-1][j];
            }
        }
        int mx=-1,indx,tmp;
        for(int i=0;i<r;i++){
            stack<int> st;
            for(int j=0;j<c;j++){
                if(st.empty() || grid[i][j]>=grid[i][st.top()])
                    st.push(j);
                else{
                    while(!st.empty() && grid[i][j]<grid[i][st.top()]){
                        indx=st.top();
                        st.pop();
                        tmp=(st.empty())?-1:st.top();
                        mx=max(mx,grid[i][indx]*(j-tmp-1));
                    }
                    st.push(j);
                }
            }//end of col.   
            while(!st.empty())
            {
                indx=st.top();
                st.pop();
                tmp=(st.empty())?-1:st.top();
                mx=max(mx,grid[i][indx]*(c-tmp-1));
            }
        }// end of row.
        return mx;
    }
};