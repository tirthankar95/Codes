typedef vector<int> vi;
typedef long long ll;
const int MOD=1e9+7;

class Solution {
    unordered_map<int,ll> dp;
    unordered_map<int,vi> adj;
    ll dfs(int src){
        if(dp.find(src)!=dp.end())return dp[src];
        ll res=1;
        for(int i=0;i<adj[src].size();i++){
            res=(res+dfs(adj[src][i])*dfs(src/adj[src][i]))%MOD;    
        }
        return dp[src]=res;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,bool> isPresent;
        int n=arr.size();
        for(int i=0;i<n;i++)isPresent[arr[i]]=true;
        adj.clear();dp.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && isPresent[arr[i]/arr[j]])
                    adj[arr[i]].push_back(arr[j]);
            }
        }//end of outer for. 
        ll res=0;
        for(int i=0;i<n;i++)
            res=(res+dfs(arr[i]))%MOD;
        return res;
    }
};