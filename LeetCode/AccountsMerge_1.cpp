typedef vector<int> vi;
typedef vector<string> vs;
class Graph{
    int n;
    vector<int>* adj;
public:
    Graph(int n){
      this->n=n;
      adj=new vector<int>[n];
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int src,vector<bool>& vis,vector<int>& family){
        vis[src]=true;
        family.push_back(src);
        for(int i=0;i<adj[src].size();i++){
            if(!vis[adj[src][i]])
                dfs(adj[src][i],vis,family);
        }
    }
};
class UnionFind{
    vector<int> sz;
    vector<int> par;
    int n;
    int root(int x){
        while(par[x]!=x){
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
public:
    UnionFind(int n){
        this->n=n;
        sz.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    void union_(int a,int b){
        int ra=root(a);
        int rb=root(b);
        if(ra==rb)return;
        if(sz[ra]<sz[rb]){
            sz[rb]+=sz[ra];
            par[ra]=rb;
        }
        else{
            sz[ra]+=sz[rb];
            par[rb]=ra;
        }
    }
    bool isInSameSet(int a,int b){
        return root(a)==root(b);
    }
};
class Solution {
    map<string,int> hashMap;
    vector<string> removeDuplicates(vector<string>& arr){
        int n=arr.size();
        int sz=0;
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i])continue;
            else sz++;
        }
        sz++;int iter=0;
        vector<string> res(sz);
        res[iter++]=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]==arr[i])continue;
            else res[iter++]=arr[i];
        }
        return res;
    }
    void concat(vs& a,vs& b){
        
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size(),m;
        vector<vector<string>> ans;
        hashMap.clear();
        Graph obj(n);
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            m=accounts[i].size();
            for(int j=1;j<m;j++){
                if(hashMap.find(accounts[i][j])!=hashMap.end())
                {
                    if(!uf.isInSameSet(i,hashMap[accounts[i][j]]))
                    {
                        obj.addEdge(i,hashMap[accounts[i][j]]);
                        uf.union_(i,hashMap[accounts[i][j]]);
                    }

                }
                else hashMap[accounts[i][j]]=i;
            }
        }//end of for-i.
        vector<bool> vis(n,false);
        vs tmp0,tmp1;vi family;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                family.clear();
                obj.dfs(i,vis,family);
                tmp0=accounts[family[0]];
                for(int j=1;j<family.size();j++){
                    tmp1=accounts[family[j]];
                    tmp1.erase(tmp1.begin());
                    tmp0.insert(tmp0.end(),tmp1.begin(),tmp1.end());
                }
                sort(tmp0.begin()+1,tmp0.end());
                tmp0=removeDuplicates(tmp0);
                ans.push_back(tmp0);
            }
        }
        return ans;
    }
};