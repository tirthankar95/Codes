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
 */const int mxSize0=1e4+1;
const int mxSize1=1e4+1; // ideally it should be 26*2000
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