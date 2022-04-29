//#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef enum{
        NO_COLOR,
        BLUE,
        RED
    };
    bool dfs(int src,vvi& graph,int current_color,vi& coloring){
        int m=graph[src].size();
        int new_color=(current_color==BLUE)?RED:BLUE;
        bool res=true;
        for(int i=0;i<m;i++){
            if(coloring[graph[src][i]]==NO_COLOR)
            {
                coloring[graph[src][i]]=current_color;
                res=res&dfs(graph[src][i],graph,new_color,coloring);
            }
            if(!res || coloring[graph[src][i]]!=current_color)
                return false;
        }//end of for.
        return res;
    }
public:
    bool isBipartite(vvi& graph) {
        int n=graph.size();
        vi coloring(n,NO_COLOR);
        bool res=true;
        for(int i=0;i<n;i++)
        {
            if(coloring[i]==NO_COLOR)
            {
                coloring[i]=BLUE;
                res=res&dfs(i,graph,RED,coloring);
            }
        }
#ifdef DBG
        for(int i=0;i<n;i++)
            cout<<i<<"->"<<coloring[i]<<" ";
        cout<<endl;
#endif
        return res;
    }
};