typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxSize=26;
class UF{
    vi parent;
    vector<long long> sz;
    int n;
public:
    UF(int n){
        this->n=n;
        parent.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        sz.resize(n,1);
    }
    void union_(int a,int b){
        int rootA=root(a);
        int rootB=root(b);
        if(rootA==rootB)return;
        if(sz[rootA]>=sz[rootB]){
            sz[rootA]=sz[rootA]+sz[rootB];
            parent[rootB]=parent[rootA];
        }
        else{
            sz[rootB]=sz[rootB]+sz[rootA];
            parent[rootA]=parent[rootB];
        }
    }//end of union_.
    int root(int a){
        while(a!=parent[a]){
            parent[a]=parent[parent[a]];
            a=parent[a];
        }
        return a;
    }//end of root.
};
class Solution {    
public:
    string smallestStringWithSwaps(string s, vvi& pairs) {
        int n=s.length();
        UF obj(n);
        int m=pairs.size();
        for(int i=0;i<m;i++)
            obj.union_(pairs[i][0],pairs[i][1]);
        unordered_map<int,int> root_aindx;
        int aindx=0;
        vvi grp;
        for(int i=0;i<n;i++){
            if(root_aindx.find(obj.root(i))==root_aindx.end())
            {
                root_aindx[obj.root(i)]=aindx++;
                grp.push_back({i});
            }
            else 
                grp[root_aindx[obj.root(i)]].push_back(i);
        }//end of for. 
        int freqMap[mxSize];
        for(int i=0;i<aindx;i++){
            sort(grp[i].begin(),grp[i].end());
            memset(freqMap,0,sizeof(freqMap));
            for(int j=0;j<grp[i].size();j++)
                freqMap[(int)(s[grp[i][j]]-'a')]++;
            int rIndex=0;
            for(int j=0;j<mxSize;j++)
            {
                for(int k=0;k<freqMap[j];k++)
                    s[grp[i][rIndex++]]=(char)('a'+j);    
            }
        }//end of for-i.
        return s;
    }
};