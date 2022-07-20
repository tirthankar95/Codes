// TLE 

const int mxChild=26;
struct node{
    node* child[mxChild];
    int isLeaf;
};
node* getNode(){
    node* temp=new node;
    temp->isLeaf=0;
    for(int i=0;i<mxChild;i++)temp->child[i]=NULL;
    return temp;
}

class Trie{
    node* root;
    inline int N(char ch){
        return (int)(ch-'a');
    }
public:
    Trie(){root=getNode();}
    node* getRoot(){return root;}
    void insert(string s){
        int n=s.length();
        node* iter=root;
        for(int i=0;i<n;i++){
            if(iter->child[N(s[i])]==NULL)
                iter->child[N(s[i])]=getNode();
            iter=iter->child[N(s[i])];
        }
        iter->isLeaf++;
    }
    int findSp(string s,int lb,node* iter){
        int n=s.length();
        int cnt=(iter->isLeaf)?iter->isLeaf:0;
        vector<bool> notAllowed(mxChild,false);
        for(int i=lb;i<n;i++){
            if(iter->child[N(s[i])] && !notAllowed[N(s[i])])
            {
                cnt+=findSp(s,i+1,iter->child[N(s[i])]);
                notAllowed[N(s[i])]=true;
            }
        }//end-i.
        return cnt;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        Trie obj;
        for(int i=0;i<n;i++)obj.insert(words[i]);
        return obj.findSp(s,0,obj.getRoot());
    }
};

// Better, accepted but still not good enough

//#define DBG
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mxChild=26;
struct node{
    node* child[mxChild];
    int isLeaf;
};
const int mxMem=1e6+1;
node mem[mxMem];
int memPool=0;
node* getNode(){
    node* temp=&mem[memPool];
    memPool=(memPool+1)%mxMem;
    temp->isLeaf=0;
    for(int i=0;i<mxChild;i++)temp->child[i]=NULL;
    return temp;
}

inline int N(char ch){return (int)(ch-'a');}
class Trie{
    node* root;
public:
    Trie(){root=getNode();}
    node* getRoot(){return root;}
    void insert(string s){
        int n=s.length();
        node* iter=root;
        for(int i=0;i<n;i++){
            if(iter->child[N(s[i])]==NULL)
                iter->child[N(s[i])]=getNode();
            iter=iter->child[N(s[i])];
        }
        iter->isLeaf++;
    }
    int findSp(vvi& table,int lb,node* iter){
        int cnt=(iter->isLeaf)?iter->isLeaf:0;
        for(int i=0;i<mxChild;i++){
            if(iter->child[i] && table[lb][i]!=-1)
                cnt+=findSp(table,table[lb][i],iter->child[i]); 
        }//end-i.
        return cnt;
    }
};
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size();
        Trie obj;
        for(int i=0;i<n;i++)obj.insert(words[i]);
        int ns=s.length();
        vvi table(ns+1,vector<int>(mxChild,0));
        vi temp(mxChild,-1);
        for(int i=ns;i>0;i--){
            for(int j=0;j<mxChild;j++)
                table[i][j]=temp[j];
            temp[N(s[i-1])]=i;
        }
        for(int j=0;j<mxChild;j++)table[0][j]=temp[j];
#ifdef DBG
        {//PRINT
            for(int i=0;i<=ns;i++){
                for(int j=0;j<mxChild;j++)
                    cout<<table[i][j]<<" ";
                cout<<endl;
            }
        }//PRINT
#endif
        return obj.findSp(table,0,obj.getRoot());
    }
};