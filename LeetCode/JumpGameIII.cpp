const int mxSize=5e4+1;
bool isVis[mxSize];
typedef vector<int> vi;
class Solution {
    int N;
    bool dfs(int src,vi& arr){
        if(arr[src]==0)return true;
        isVis[src]=true;
        int res=false;
        if(src-arr[src]>=0 && !isVis[src-arr[src]])res|=dfs(src-arr[src],arr);
        if(!res && src+arr[src]<N && !isVis[src+arr[src]])res|=dfs(src+arr[src],arr);
        return res;
    }
public:
    bool canReach(vi& arr, int start) {
        N=arr.size();
        memset(isVis,false,N*sizeof(bool));
        return dfs(start,arr);
    }
};