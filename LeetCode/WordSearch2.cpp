typedef pair<int,int> ii;
static int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int mxSize=(int)('z'-'a')+1;
struct node{
    int isLeaf;
    node* children[mxSize];
};
node* getNode(){
    node* tmp=new node;
    for(int i=0;i<mxSize;i++)
        tmp->children[i]=NULL;
    tmp->isLeaf=-1;
    return tmp;
}
class Trie{
    public:
    node* root;
    Trie(){
        root=getNode();
    }
    void insert(string s,int val){
        int n=s.length();
        node* iter=root;
        for(int i=0;i<n;i++)
        {
            if(iter->children[(int)(s[i]-'a')]==NULL)
                iter->children[(int)(s[i]-'a')]=getNode();
            iter=iter->children[(int)(s[i]-'a')];
        }
        iter->isLeaf=val;
    }
};
class Solution {
    int n,m;
    vector<string> sol;
    vector<string> words;
    vector<vector<bool>> vis;
    vector<bool> used;
    void dfs(ii src,vector<vector<char>>& board,node* iter){
        if(iter->isLeaf!=-1)
        {
            if(!used[iter->isLeaf])
            {
                used[iter->isLeaf]=true;
                sol.push_back(words[iter->isLeaf]);
            }
        }
        char ch;
        int ip,jp;
        vis[src.first][src.second]=true;
        for(int i=0;i<mxSize;i++)
        {
            if(iter->children[i]==NULL)continue;
            ch=(char)('a'+i);
            for(int it=0;it<4;it++)
            {
                ip=src.first+dir[it][0];
                jp=src.second+dir[it][1];
                if(ip<0 || jp<0 || ip>=n || jp>=m || vis[ip][jp] || board[ip][jp]!=ch)continue;
                dfs(ii(ip,jp),board,iter->children[i]);
            }
        }//end of for-i.
        vis[src.first][src.second]=false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words1){
        n=board.size();
        m=board[0].size();
        sol.clear();
        words=words1;Trie obj;
        for(int i=0;i<words.size();i++)obj.insert(words[i],i);
        node* root=obj.root;
        vis.resize(n,vector<bool>(m,false));
        used.resize(words.size(),false);
        for(int i=0;i<mxSize;i++)
        {
            if(!root->children[i])continue;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    char ch=(char)('a'+i);
                    if(ch==board[j][k])
                        dfs(ii(j,k),board,root->children[i]);       
                }//end of k
            }//end of j
        }//end of i
        return sol;
    }
};