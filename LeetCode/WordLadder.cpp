typedef vector<int> vi;
class Graph{
public:
    int n;
    vi* adj;
    Graph(int n){
        this->n=n;
        adj=new vi[n];
    }    
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> hashMap;
        wordList.push_back(beginWord);
        int n=wordList.size();
        for(int i=0;i<n;i++)
            hashMap[wordList[i]]=i;
        if(hashMap.find(endWord)==hashMap.end())
            return 0;
        Graph ob(n);
        char temp;
        int m=wordList[0].length();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp=wordList[i][j];
                for(int k=0;k<26;k++){
                    wordList[i][j]=(char)('a'+k);
                    if(temp!=wordList[i][j] && hashMap.find(wordList[i])!=hashMap.end())
                        ob.addEdge(i,hashMap[wordList[i]]);
                }//end of for-k.
                wordList[i][j]=temp;
            }//end of for-j.
        }//end of for-i.
        queue<int> Q;
        vi parent(n,-1);parent[n-1]=1;
        Q.push(n-1);
        while(!Q.empty()){
            int src=Q.front();
            Q.pop();
            for(int i=0;i<ob.adj[src].size();i++){
                if(parent[ob.adj[src][i]]!=-1)
                    continue;
                parent[ob.adj[src][i]]=parent[src]+1;
                Q.push(ob.adj[src][i]);
                if(wordList[ob.adj[src][i]]==endWord)
                    return parent[ob.adj[src][i]];
            }//end of for.
        }//end of while. 
        return 0;
    }
};