typedef vector<int> vi;
const int mxSize=16;
int visited[mxSize];

class Solution {
    int R;
    vector<vi> path;
    void dfs(vector<vi>& graph,vi& tmp,int i){
        int child;  
        if(i==R-1){
            path.push_back(tmp);
            return;
        }
        for(int iter=0;iter<graph[i].size();iter++){
            child=graph[i][iter];
            if(visited[child])continue;
            tmp.push_back(child);visited[i]=true;
            dfs(graph,tmp,child);
            tmp.pop_back();visited[i]=false;
        }  
    }
public:
    vector<vi> allPathsSourceTarget(vector<vi>& graph) {
        R=graph.size();
        memset(visited,false,sizeof(visited));
        path.clear();
        vi tmp;
        tmp.push_back(0);visited[0]=true;
        dfs(graph,tmp,0);
        return path;
    }
};