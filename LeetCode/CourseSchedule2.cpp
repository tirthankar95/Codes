typedef vector<int> vi;
class Graph{
    int n;
    vi* adj;
public:
    Graph(int n){
        this->n=n;
        adj=new vi[n];
    }
    void addEdge(int u,int v){
        adj[v].push_back(u);
    }
    // returns true if there is a cycle.
    bool tSortUtil(int src,vector<bool>& vis,vector<bool>& visLoc,vi& stack,int& stackPtr){
        vis[src]=true;
        visLoc[src]=true;
        int child;
        for(int i=0;i<adj[src].size();i++){
            child=adj[src][i];
            if(!vis[child])
            {
                if(tSortUtil(child,vis,visLoc,stack,stackPtr))
                    return true;
            }
            else if(visLoc[child])return true;
        }//end of for.
        stack[stackPtr++]=src;
        visLoc[src]=false;
        return false;
    }
    vi tSort(){
        vector<bool> vis(n,false);
        vector<bool> visLoc(n,false);
        vi stack(n);int stackPtr=0,iter=0;
        vi empty;
        bool isCycle;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                isCycle=false;
                isCycle=tSortUtil(i,vis,visLoc,stack,stackPtr);
                if(isCycle)return empty;
            }
        }//end of for.
        empty.resize(n);
        while(stackPtr){
            empty[iter++]=stack[--stackPtr];
        }
        return empty;
    }
};
class Solution {
public:
    vi findOrder(int numCourses, vector<vi>& pre) {
        int sz=pre.size();
        vi sol;
        if(sz==0){
            sol.resize(numCourses);
            for(int i=0;i<numCourses;i++)sol[i]=i;
            return sol;
        }
        Graph obj(numCourses);
        for(int i=0;i<sz;i++)
            obj.addEdge(pre[i][0],pre[i][1]);
        return obj.tSort();
    }
};