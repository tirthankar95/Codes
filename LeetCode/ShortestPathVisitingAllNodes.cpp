https://leetcode.com/problems/shortest-path-visiting-all-nodes/solution/
// 1->not visited.
// 0->visisted.
typedef vector<int> vi;
const int mxSize1=12+1,mxSize2=(1<<13)+1;
int dp[mxSize1][mxSize2];
#define inf (1e9+7);
class Solution {
    int N;
    int dfs(vector<vi>& graph,int cNode,int vFlag){
        if((vFlag&(vFlag-1))==0)
            return 0;
        if(dp[cNode][vFlag]!=-1)
            return dp[cNode][vFlag];
        dp[cNode][vFlag]=inf; // to indicate that the node has been visited.
        int j,temp=inf;int vFlagC;
        for(int i=0;i<graph[cNode].size();i++){
            j=graph[cNode][i];
            if((vFlag&(1<<j))!=0)//j-th neighbor not visited.
            {
                vFlagC=vFlag^(1<<cNode);
                temp=min(temp,min(dfs(graph,j,vFlagC),dfs(graph,j,vFlag)));
            }
        }//end of for.
        dp[cNode][vFlag]=min(dp[cNode][vFlag],1+temp);
        return dp[cNode][vFlag];
    }
public:
    int shortestPathLength(vector<vi>& graph) {
        N=graph.size();
        int lim1=N,lim2=1<<N;
        //Clearing Memory.
        for(int i=0;i<lim1;i++)
            for(int j=0;j<lim2;j++)
                dp[i][j]=-1;
        int res=inf;
        for(int src=0;src<N;src++)
            res=min(res,dfs(graph,src,lim2-1));
        return res;
    }
};