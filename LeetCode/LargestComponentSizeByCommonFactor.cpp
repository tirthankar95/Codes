typedef vector<int> vi;
const int mxSize=1e5+1;
bool seive[mxSize];
class UnionFind{
    vi arr;
    vi sz;
    int n;
    int root(int x){
        while(arr[x]!=x){
            arr[x]=arr[arr[x]];
            x=arr[x];
        }
        return x;
    }
public:
    UnionFind(int n){
        this->n=n;
        arr.resize(n);
        for(int i=0;i<n;i++)arr[i]=i;
        sz.resize(n,1);
    }
    void union_(int a,int b){
        int ra=root(a);
        int rb=root(b);
        if(ra==rb)return;
        if(sz[ra]>=sz[rb]){
            sz[ra]+=sz[rb];
            arr[rb]=ra;
        }
        else{
            sz[rb]+=sz[ra];
            arr[ra]=rb;
        }
    }
    int getMax(){
        int mx=1;
        for(int i=0;i<n;i++)
            mx=max(mx,sz[i]);
        return mx;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> hashMap;
        hashMap[nums[0]]=0;
        int mx=nums[0],first;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            hashMap[nums[i]]=i;
        }
        memset(seive,false,sizeof(bool)*(mx+1));
        seive[0]=seive[1]=true;
        UnionFind obj(n);
        for(int i=2;i<=mx;i++)
        {
            if(seive[i])continue;
            first=-1;
            for(int j=i;j<=mx;j+=i){
                seive[j]=true;
                if(hashMap.find(j)!=hashMap.end())
                {
                    if(first==-1)first=hashMap[j];
                    else obj.union_(first,hashMap[j]);
                }
            }//end of for-j.
        }//end of for-i.
        return obj.getMax();
    }
};