//#define DBG
typedef vector<string> vs;
typedef pair<int,double> id;

class Solution {
public:
    map<string,int> sMapi;
    class Graph{
        int n;
        vector<id>* graph;
        public:
        unordered_map<int,double> val;
        unordered_map<int,int> col;
        Graph(int n){
            this->n=n;
            graph=new vector<id>[n];
        }
        void addEdge(int u,int v,double factor){
            graph[v].push_back( id(u,factor) );
            graph[u].push_back( id(v,(double)(1/factor)) );
        }
        void dfs(int src,vector<bool>& vis,double value,int color){
            vis[src]=true;col[src]=color;
            val[src]=value;
            for(int i=0;i<graph[src].size();i++){
                if(!vis[graph[src][i].first])
                    dfs(graph[src][i].first,vis,value*graph[src][i].second,color);
            }
        }//end of dfs.
    };
    vector<double> calcEquation(vector<vs>& equations, vector<double>& values, vector<vs>& queries) {
        int n=equations.size();
        Graph obj(2*n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++)
            {
                if(sMapi.find(equations[i][j])==sMapi.end())
                    sMapi[equations[i][j]]=cnt++;
            }//end of for-j.
            obj.addEdge(sMapi[equations[i][0]],sMapi[equations[i][1]],values[i]);
        }
        vector<bool> vis(cnt,false);
        int color=0;
        for(int i=0;i<cnt;i++){
            if(!vis[i])
                obj.dfs(i,vis,1,color++);
        }
#ifdef DBG
        for(int i=0;i<cnt;i++)
            cout<<i<<"~ "<<obj.val[i]<<", ";
        cout<<endl;
#endif
        int m=queries.size();
        vector<double> res(m);
        string u,v;
        for(int i=0;i<m;i++){
            u=queries[i][0],v=queries[i][1];
            if(sMapi.find(u)==sMapi.end() || sMapi.find(v)==sMapi.end() || obj.col[sMapi[u]]!=obj.col[sMapi[v]])
                res[i]=-1;
            else 
                res[i]=((double)(obj.val[sMapi[u]]/obj.val[sMapi[v]]));
        }
        return res;
    }
};