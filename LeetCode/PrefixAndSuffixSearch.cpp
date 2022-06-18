/*
https://leetcode.com/problems/prefix-and-suffix-search/solution/
Approach #3: Trie of Suffix Wrapped Words [Accepted]
Intuition and Algorithm

Consider the word 'apple'. For each suffix of the word, we could insert that suffix, followed by '#', followed by the word, all into the trie.

For example, we will insert '#apple', 'e#apple', 'le#apple', 'ple#apple', 'pple#apple', 'apple#apple' into the trie. Then for a query like prefix = "ap", suffix = "le", we can find it by querying our trie for le#ap.
*/
const int mxSize=27;
struct node{
    node* children[mxSize];
    int index;
};
node* getNode(){
    node* temp=new node;
    for(int i=0;i<mxSize;i++)temp->children[i]=NULL;
    temp->index=-1;
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
            id=(id<0 || id>=26)?26:id;
            if(!iter->children[id])
                iter->children[id]=getNode();
            iter=iter->children[id];
            iter->index=max(iter->index,val);
        }
    }
    int find(string s){
        int n=s.length(),id;
        node* iter=root;
        for(int i=0;i<n;i++){
            id=(int)(s[i]-'a');
            id=(id<0 || id>=26)?26:id;
            if(!iter->children[id])
                return -1;
            iter=iter->children[id];
        }
        return iter->index;
    }
};
class WordFilter {
    Trie* obj;
public:
    WordFilter(vector<string>& words) {
        obj=new Trie;
        int sz=words.size(),str_len;
        for(int i=0;i<sz;i++){
            string word="#"+words[i];
            str_len=words[i].length();
            for(int j=0;j<str_len;j++)
            {
                word=words[i][str_len-j-1]+word;
                obj->insert(word,i);
            }//end of inner for.
        }//end of outer for.
    }
    int f(string prefix, string suffix) {
        return obj->find(suffix+"#"+prefix);
    }
};
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */