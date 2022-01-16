#define TWO (2)
typedef vector<int> vi;
typedef pair<int,int> ii;
const int mxSize=5e4+1;
bool vis[mxSize];
static int delta[TWO]={-1,1};
unordered_map<int,vi> link;

class Solution {
public:
    int minJumps(vi& arr) {
        int n=arr.size();
        link.clear();
        for(int i=0;i<n;i++)
        {
            link[arr[i]].push_back(i);
            vis[i]=false;
        }
        queue<ii> qu;
        qu.push(ii(0,0));
        vis[0]=true;
        int src,dist,id;
        while(!qu.empty()){
            src=qu.front().first;
            dist=qu.front().second;
            if(src==n-1)return dist;
            qu.pop();
            for(int i=0;i<TWO;i++){
                if(src+delta[i]==n-1)return dist+1;
                if(src+delta[i]>=0 && src+delta[i]<n && !vis[src+delta[i]]){
                    qu.push(ii(src+delta[i],dist+1));
                    vis[src+delta[i]]=true;
                }
            }//end of for(1). 
            for(int i=0;i<link[arr[src]].size();i++){
                id=link[arr[src]][i];
                if(id==n-1)return dist+1;
                if(!vis[id]){
                    qu.push(ii(id,dist+1));
                    vis[id]=true;
                }
            }//end of for(2).
            link.erase(arr[src]);
        }
        return n;
    }
};