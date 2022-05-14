//#define DBG
typedef pair<int,int> ii;
class Graph{
    int N;
    vector<ii>* edges;    
public:
    Graph(int n){
        N=n;
        edges=new vector<ii>[N];
    }
    void addEdge(int u,int v,int wt){
        edges[u-1].push_back(ii(v-1,wt));
    }
    void print(){
        for(int i=0;i<N;i++)
            cout<<i<<" z "<<edges[i].size()<<endl;
        cout<<endl;
    }
    int dijkstra(int src){
        vector<int> dist(N,INT_MAX);
        dist[src-1]=0;
        priority_queue<ii> pq;
        pq.push(ii(0,src-1));
        ii element0,element1;
        while(!pq.empty()){
            element0=pq.top();
            pq.pop();
            for(int j=0;j<edges[element0.second].size();j++){
                element1=edges[element0.second][j];
                if(dist[element1.first]==INT_MAX || dist[element1.first]>dist[element0.second]+element1.second){
                    dist[element1.first]=dist[element0.second]+element1.second;
                    pq.push(ii(-dist[element1.first],element1.first));
                }
            }//end of inner-for.
        }//end of outer-for.
        int mx=INT_MIN;
        for(int i=0;i<N;i++){
            mx=max(mx,dist[i]);
#ifdef DBG
            cout<<i<<" "<<dist[i]<<endl;
#endif
        }
        return (mx==INT_MAX)?-1:mx;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph graph(n);
        for(int i=0;i<times.size();i++)
            graph.addEdge(times[i][0],times[i][1],times[i][2]);
        return graph.dijkstra(k);
    }
};