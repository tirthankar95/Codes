https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
/* Explanation 
A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. For example, there are 3 SCCs in the following graph.
 */
 //#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;

class graph{
public:
    int N;
    vector<int>* adj;
    graph(int N){
        this->N=N;
        adj=new vector<int>[N];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
class Solution {
    int cnt;
    void scc_(int parent,int u,vi* connections,vi& low,vi& disc,vector<bool>& vis,vi& scc,stack<int>& st){
        static int time=0;
        low[u]=disc[u]=(time++);
        st.push(u);
        vis[u]=true;
        int v;
        for(int i=0;i<connections[u].size();i++){
            v=connections[u][i];
            if(disc[v]==-1){
                scc_(u,v,connections,low,disc,vis,scc,st);
                low[u]=min(low[u],low[v]);
            }
// Update low value of 'u' only of 'v' is still in stack
// (i.e. it's a back edge, not cross edge).
// Case 2 (per above discussion on Disc and Low value)
            else if(vis[v] && v!=parent){
                low[u]=min(low[u],disc[v]);
            }
        }//end of for.
        if(disc[u]==low[u]){
            while(st.top()!=u){
                scc[st.top()]=cnt;
                vis[st.top()]=false;
                st.pop();
            }
            scc[st.top()]=cnt;
            vis[st.top()]=false;
            st.pop();
            cnt++;
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vi low(n,-1);
        vi disc(n,-1);//discovery
        vector<bool> vis(n,false);
        vi scc(n,-1);
        stack<int> st;
        cnt=0;
        graph obj(n);
        for(int i=0;i<connections.size();i++)
            obj.addEdge(connections[i][0],connections[i][1]);
        for(int i=0;i<n;i++)
        {
            if(disc[i]==-1)
                scc_(-1,i,obj.adj,low,disc,vis,scc,st);
        }
#ifdef DBG
        for(int i=0;i<n;i++)
            cout<<i<<" "<<scc[i]<<endl;
        cout<<endl;
#endif
        vvi sol;
        for(int i=0;i<connections.size();i++)
            if(scc[connections[i][0]]!=scc[connections[i][1]])
                sol.push_back({connections[i][0],connections[i][1]});
        return sol;
    }
};