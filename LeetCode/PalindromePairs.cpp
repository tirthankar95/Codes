typedef vector<int> vi;
typedef vector<vi> vvi;
const int cMax=(int)('z'-'a'+1);

struct node{
    node* children[cMax];
    int isLeaf;
};
node* create()
{
    node* tmp=new node;
    tmp->isLeaf=-1;// -1 if its not leaf. 
    for(int i=0;i<cMax;i++)
        tmp->children[i]=NULL;
    return tmp;
}
void insert(node* root,string s,int indx)
{
    int n=s.length();
    int i=0;node* iter=root;
    while(i<n)
    {
        if(iter->children[(int)(s[i]-'a')]==NULL)
            iter->children[(int)(s[i]-'a')]=create();
        iter=iter->children[(int)(s[i]-'a')];
        i++;
    }
    iter->isLeaf=indx;
}
void dfs(node* root,vi& sol)
{
    if(root->isLeaf!=-1)sol.push_back(root->isLeaf);
    for(int i=0;i<cMax;i++)
        if(root->children[i]!=NULL)
            dfs(root->children[i],sol);
}
vi found(node* root,string s)
{
    vi sol;
    int n=s.length();
    int i=0;node* iter=root;
    while(i<n)
    {
        if(iter->isLeaf!=-1)sol.push_back(iter->isLeaf);
        if(iter->children[(int)(s[i]-'a')]==NULL)
            return sol;
        iter=iter->children[(int)(s[i]-'a')];
        i++;
    }
    dfs(iter,sol);
    return sol;
}
string reverseString(string s)
{
    int n=s.length();
    string res;
    res.resize(n);
    for(int i=0;i<n;i++)
        res[n-i-1]=s[i];
    return res;
}
bool isPalin(string s)
{
    int lb=0;int ub=s.length()-1;
    while(lb<=ub)
    {
        if(s[lb]!=s[ub])return false;
        lb++;
        ub--;
    }
    return true;
}
class Solution {
    int N;
public:
    vvi palindromePairs(vector<string>& words) {
        N=words.size();
        node*  root=create();
        for(int i=0;i<N;i++)
            insert(root,words[i],i);
        string rev="";
        vvi sol;
        vi tmp;
        for(int i=0;i<N;i++)
        {
            rev=reverseString(words[i]);
            tmp=found(root,rev);
            for(int j=0;j<tmp.size();j++)
            {
                if(tmp[j]!=i && isPalin(words[tmp[j]]+words[i]))
                    sol.push_back(vi({tmp[j],i}));
            }
        }//end of outer-for.(main)
        return sol;
    }
};