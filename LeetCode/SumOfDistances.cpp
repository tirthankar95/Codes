typedef vector<int> vi;
class Solution {
    int update(vector<vi>& adj,vi& count,vi& dist,vector<int>& parent,int src,int par,int lvl)
    {
        parent[src]=par;
        count[src]=1;
        dist[src]=lvl;
        for(int i=0;i<adj[src].size();i++)
        {
            if(parent[src]!=adj[src][i])
            {
                count[src]+=update(adj,count,dist,parent,adj[src][i],src,lvl+1);
            }
        }
        return count[src];
    }
public:
    vi sumOfDistancesInTree(int n, vector<vi>& edges) {
//  ...................................  //
        vi count(n,0);
        vi dist(n,0);
        vi sol(n);
        vi parent(n,-1);
        vector<vi> adj(n);
//  ...................................  //
        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
//  ...................................  //
        update(adj,count,dist,parent,0,-1,0);
        int sum=0;
        for(int i=0;i<n;i++)sum+=dist[i];
//  ...................................  //
        sol[0]=sum;
        int id;
        queue<int> qu;qu.push(0);
        while(!qu.empty())
        {
            int src=qu.front();
            qu.pop();
            for(int i=0;i<adj[src].size();i++)
            {
                if(parent[src]!=adj[src][i])
                {
                    id=adj[src][i];
                    sol[id]=sol[src]+(n-2*count[id]);
                    qu.push(id);
                }
            }
        }
        return sol;
    }
};