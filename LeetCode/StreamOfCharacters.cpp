/* Not optimized
const int mxSize=1e4+1;
// #define DBG
#ifdef DBG
    int gCount=0;
#endif
class node{
    const static int mxSize=26;
    node* children[mxSize];
    bool isLeaf;
 public:
#ifdef DBG
    int id;
#endif
    node(){
        for(int i=0;i<mxSize;i++)
            children[i]=NULL;
#ifdef DBG
        id=gCount++;
#endif
        isLeaf=false;
    }
    node* getChildren(int indx){return children[indx];}
    bool getLeaf(){return isLeaf;}
    void assign(int indx){children[indx]=new node();}
    void stop(){isLeaf=true;}
};
class Trie{
    node* root;
    node** potential;
    int potentialSz;
 public:
    Trie(){
        root=new node();
        potential=new node*[mxSize];
        potentialSz=0;
    }
    void insert(string word){
        node* iter=root;
        int n=word.length(),ch;
        for(int i=0;i<n;i++){
            ch=(int)(word[i]-'a');
            if(iter->getChildren(ch)==NULL)
                iter->assign(ch);
            iter=iter->getChildren(ch);
        }
        iter->stop();
    }
    bool found(char ch){
        bool res=false;
        int charId=(int)(ch-'a');
        if(root->getChildren(charId)!=NULL)
        {
#ifdef DBG
            cout<<ch<<"*"<<root->id<<endl;
#endif
            potential[potentialSz++]=root;
        }
#ifdef DBG
        cout<<"-------\n";
#endif
        for(int i=0;i<potentialSz;i++){
#ifdef DBG
            cout<<potential[i]->id<<endl;
            if(ch=='f'){
                cout<<"OK1\n";
            }
#endif
            if(potential[i]->getChildren(charId)!=NULL)
            {
#ifdef DBG
                if(ch=='f')cout<<"OK2\n";
#endif
                potential[i]=potential[i]->getChildren(charId);
                if(potential[i]->getLeaf())res=true;
            }
            else{
                swap(potential[i],potential[potentialSz-1]);
                i--;potentialSz--;
            }
        }
        return res;
    }
};
class StreamChecker {
    Trie* obj;
public:
    StreamChecker(vector<string>& words) {
        obj=new Trie();
        for(int i=0;i<words.size();i++)
            obj->insert(words[i]);
    }  
    bool query(char letter) {
        return obj->found(letter);
    }
};
 */
const int mxSize0=1e4+1;
const int mxSize1=4e4+1;
struct node{
    node* children[26];
    bool isLeaf;  
};
node pool[mxSize1];
int poolPtr=0;
node* create(){
    node* tmp=&pool[poolPtr];
    poolPtr=(poolPtr+1)%mxSize1;
    for(int i=0;i<26;i++)
        tmp->children[i]=NULL;
    tmp->isLeaf=false;
    return tmp;
}
node* potential[mxSize0];
class Trie{
    node* root;
    int potentialSz;
 public:
    Trie(){
        root=new node();
        potentialSz=0;
    }
    void insert(string word){
        node* iter=root;
        int n=word.length(),ch;
        for(int i=0;i<n;i++){
            ch=(int)(word[i]-'a');
            if(iter->children[ch]==NULL)
                iter->children[ch]=create();
            iter=iter->children[ch];
        }
        iter->isLeaf=true;
    }
    bool found(char ch){
        bool res=false;
        int charId=(int)(ch-'a');
        if(root->children[charId]!=NULL)
        {
            potential[potentialSz++]=root;
        }
        for(int i=0;i<potentialSz;i++){
            if(potential[i]->children[charId]!=NULL)
            {
                potential[i]=potential[i]->children[charId];
                if(potential[i]->isLeaf)res=true;
            }
            else{
                swap(potential[i],potential[potentialSz-1]);
                i--;potentialSz--;
            }
        }
        return res;
    }
};
class StreamChecker {
    Trie* obj;
public:
    StreamChecker(vector<string>& words) {
        obj=new Trie();
        for(int i=0;i<words.size();i++)
            obj->insert(words[i]);
    }  
    bool query(char letter) {
        return obj->found(letter);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/************************************************************************/
struct Trie {
    //Trie *t[26] = {};
    int t[26] = {};
    int b = 0;
};
static Trie A[444444];

class StreamChecker {
public:
    int root;
    int ai;
    int x;
    deque<int> d;
    int GetAi() {
        memset(&(A[ai]), 0, sizeof(A[ai]));
        return ai++;
    }
    
    StreamChecker(vector<string>& ws) {
        // TODO: use hash
        ai = 0;
        root = GetAi();
        for (auto& s : ws) {
            auto p = &(A[root]);
            int i = 0;
            for (int j = s.size() - 1; j >= 0; j--) {
                i = s[j] - 'a';
                if (!p->t[i]) {
                    p->t[i] = GetAi();
                }
                if (j == 0)
                    p->b |= 1 << i;
                p = &(A[p->t[i]]);
            }
        }
    }
    
    bool query(char l) {
        d.push_front(l - 'a');
        if (d.size() > x)
            d.pop_back();
        auto p = &(A[root]);
        for (auto i : d)
            if (!p->t[i])
                return false;
            else if (p->b & (1 << i))
                return true;
            else
                p = &(A[p->t[i]]);
        return false;
    }
};
static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0;
}();
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
/************************************************************************/
