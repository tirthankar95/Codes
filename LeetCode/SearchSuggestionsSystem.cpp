//#define DBG
typedef vector<int> vi;
const int mxChild=26;
struct node{
    node* children[mxChild];
    int index[3];
    int index_;
};
node* getNode(){
    node* temp=new node;
    for(int i=0;i<mxChild;i++)
        temp->children[i]=NULL;
    temp->index_=0;
    return temp;
}

class Trie{
    node* root;
public:
    Trie(){
        root=getNode();
    }
    void insert(string s,int val){
        int n=s.length(),id;
        node* iter=root;
        for(int i=0;i<n;i++){
            id=(int)(s[i]-'a');
            if(iter->children[id]==NULL)
                iter->children[id]=getNode();
            iter=iter->children[id];
            if(iter->index_<3)
                iter->index[iter->index_++]=val;
        }//end of for-i.
    }
    vector<vector<string>> find(vector<string>& products,string s){
        int n=s.length(),id;
        vector<vector<string>> sol(n);
        node* iter=root;
        for(int i=0;i<n;i++){
            id=(int)(s[i]-'a');
            iter=iter->children[id];
            if(iter==NULL)break;
            for(int j=0;j<iter->index_;j++)
                sol[i].push_back(products[iter->index[j]]);
        }//end of for-i.
        return sol;
    }
#ifdef DBG
    void printUtil(node* root,string parent){
        string child="";bool flag=true;
        for(int i=0;i<mxChild;i++){
            if(root->children[i])
            {
                child=parent+(char)('a'+i);
                printUtil(root->children[i],child);
                flag=false;
            }
        }
        if(flag)
            cout<<parent<<endl;
    }
    void print(){
        printUtil(root,"");
    }
#endif
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n=products.size();
        Trie* obj=new Trie();
        for(int i=0;i<n;i++)
            obj->insert(products[i],i);
#ifdef DBG
        obj->print();
#endif
        return obj->find(products,searchWord);
    }
};