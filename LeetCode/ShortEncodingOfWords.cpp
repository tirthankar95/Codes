const int mxChild=26;
struct node{
    node* children[mxChild];
};
node* getNode(){
    node* temp=new node;
    for(int i=0;i<mxChild;i++)
        temp->children[i]=NULL;
    return temp;
}

class Trie{
    node* root;
public:
    Trie(){
        root=getNode();
    }
    void insert(string s){
        node* iter=root;
        int n=s.length(),id;
        for(int i=0;i<n;i++){
            id=(int)(s[i]-'a');
            if(!iter->children[id])
                iter->children[id]=getNode();
            iter=iter->children[id];
        }
    }
    bool hasNoPrefix(string s){
        node* iter=root;
        int n=s.length(),id;
        for(int i=0;i<n;i++){
            id=(int)(s[i]-'a');
            iter=iter->children[id];
        }
        for(int i=0;i<mxChild;i++)
            if(iter->children[i])return false;
        iter->children[0]=getNode();
        return true;
    }
};
class Solution {
    string reverse(string s){
        string rs=s;
        int lb=0;int ub=rs.length()-1;
        while(lb<ub){
            swap(rs[lb],rs[ub]);
            lb++;ub--;
        }
        return rs;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* obj=new Trie();
        int sz=words.size();
        for(int i=0;i<sz;i++)
            obj->insert(reverse(words[i]));
        int ans=0;
        for(int i=0;i<sz;i++)
            if(obj->hasNoPrefix(reverse(words[i])))
                ans+=(1+words[i].length());
        return ans;
    }
};
/*
Approach #1: Store Prefixes [Accepted]
Intuition

If a word X is a suffix of Y, then it does not need to be considered, as the encoding of Y in the reference string will also encode X. For example, if "me" and "time" is in words, we can throw out "me" without changing the answer.

If a word Y does not have any other word X (in the list of words) that is a suffix of Y, then Y must be part of the reference string.

Thus, the goal is to remove words from the list such that no word is a suffix of another. The final answer would be sum(word.length + 1 for word in words).

Algorithm

Since a word only has up to 7 suffixes (as words[i].length <= 7), let's iterate over all of them. For each suffix, we'll try to remove it from our words list. For efficiency, we'll make words a set.
*/
/*
Approach #2: Trie [Accepted]
Intuition

As in Approach #1, the goal is to remove words that are suffixes of another word in the list.

Algorithm

To find whether different words have the same suffix, let's put them backwards into a trie (prefix tree). For example, if we have "time" and "me", we will put "emit" and "em" into our trie.

After, the leaves of this trie (nodes with no children) represent words that have no suffix, and we will count sum(word.length + 1 for word in words)
*/