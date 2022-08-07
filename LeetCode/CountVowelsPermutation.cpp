typedef vector<int> vi;
typedef long long ll;
const int MOD=1e9+7;
const int mxVowel=5;
const int mxLen=2e4+1;
char vowel[mxVowel]={'a','e','i','o','u'};
bool first=true;
ll dp[mxVowel][mxLen];

class Solution {
    void build(vector<vi>& adj){
        //a
        adj[0]=vi{1};
        //e
        adj[1]=vi{0,2};
        //i
        adj[2]=vi{0,1,3,4};
        //o
        adj[3]=vi{2,4};
        //u
        adj[4]=vi{0};
    }
    void init(){
        int child;
        vector<vi> adj(mxVowel);
        build(adj);
        for(int i=0;i<mxVowel;i++)dp[i][1]=1;
        for(int j=2;j<mxLen;j++){
            for(int i=0;i<mxVowel;i++){
                for(int k=0;k<adj[i].size();k++)
                {
                    child=adj[i][k];
                    dp[i][j]=(dp[i][j]+dp[child][j-1])%MOD;
                }
            }//end of inner-for.
        }//end of outer-for.         
    }
public:
    int countVowelPermutation(int n) {
        if(first){
            first=false;
            init();
        }
        ll res=0;
        for(int i=0;i<mxVowel;i++)
            res=(res+dp[i][n])%MOD;
        return res;
    }
};