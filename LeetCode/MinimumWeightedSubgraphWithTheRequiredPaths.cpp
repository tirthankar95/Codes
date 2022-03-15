/*The idea is the following: paths from s1 to dest and from s2 to destcan have common pointx`. Then we need to reach:

From s1 to x, for this we use Dijkstra
From s2 to x, same.
From x to dest, for this we use Dijkstra on the reversed graph.
Finally, we check all possible x.*/
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
const ll inf=((ll)1<<62)-1;

class graph{
    int n;
    vector<ii>* adj;
public:
    int saveNode;
    graph(int n){
        this->n=n;
        adj=new vector<ii>[n];
    }
    void addEdge(int u,int v,int wt){
        adj[u].push_back({v,wt});
    }
    vector<ll> dijkstra(int src){
        vector<ll> dist(this->n,inf);
        priority_queue<ii> pq; 
        dist[src]=0;
        pq.push(ii(-0,src));
        ll child,wt;
        for(int i=0;i<this->n-1;i++){
            ll src=pq.top().second;    
            pq.pop();
            for(int i=0;i<adj[src].size();i++){
                child=adj[src][i].first;
                wt=adj[src][i].second;
                if(dist[src]+wt<=dist[child])
                {
                    dist[child]=wt+dist[src];
                    pq.push(ii(-dist[child],child));
                }
            }//end of for-j. 
        }//end of for-i.   
        return dist;
    }//end of fn.
};
class Solution {
public:
    ll minimumWeight(int n, vector<vi>& edges, int src1, int src2, int dest) {
        graph obj(n);
        int m=edges.size();
        for(int i=0;i<m;i++)
            obj.addEdge(edges[i][1],edges[i][0],edges[i][2]);
        vector<ll> distD=obj.dijkstra(dest);
        graph objNR(n);
        for(int i=0;i<m;i++)
            objNR.addEdge(edges[i][0],edges[i][1],edges[i][2]);
        vector<ll> distS2=objNR.dijkstra(src2);
        vector<ll> distS1=objNR.dijkstra(src1);
        ll mi=inf;
        for(int i=0;i<n;i++){
            if(distD[i]==inf || distS2[i]==inf || distS1[i]==inf)continue;
            mi=min(mi,distD[i]+distS2[i]+distS1[i]);
        }
        return (mi==inf)?-1:mi;
    }
};