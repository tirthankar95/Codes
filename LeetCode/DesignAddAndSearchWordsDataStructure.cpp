struct node{
    bool isLeaf;
    node* children[26];
};
node* getNode(){
    node* temp=new node;
    for(int i=0;i<26;i++)
        temp->children[i]=NULL;
    temp->isLeaf=false;
    return temp;
}

class WordDictionary {
    node* root;
    bool dfs(string word,int index,node* src){
        int n=word.length();
        while(index<n){
            if(word[index]!='.'){
                if(src->children[(int)(word[index]-'a')]==NULL)
                    return false;
                src=src->children[(int)(word[index]-'a')];
            }
            else{
                for(int j=0;j<26;j++){
                    if(src->children[j]!=NULL && dfs(word,index+1,src->children[j]))
                        return true;                    
                }
                return false;
            }
            index++;
        }//end of while.
        return (src->isLeaf==true);
    }
public:
    WordDictionary() {
        root=getNode();
    }
    void addWord(string word) {
        int n=word.length();
        node* iter=root;
        for(int i=0;i<n;i++){
            if(iter->children[(int)(word[i]-'a')]==NULL)
                iter->children[(int)(word[i]-'a')]=getNode();
            iter=iter->children[(int)(word[i]-'a')];
        }
        iter->isLeaf=true;
    }
    bool search(string word){
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */