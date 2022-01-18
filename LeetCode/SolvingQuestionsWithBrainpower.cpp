typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxSize=1e5+1;
ll dp[mxSize];

class Solution {
    int SZ;
    ll fn(vvi& questions,int index){
        if(index>=SZ)return 0;
        if(dp[index]!=-1)return dp[index];
        ll pointsA,pointsB;
        pointsA=(ll)questions[index][0]+fn(questions,index+questions[index][1]+1);
        pointsB=fn(questions,index+1);
        return dp[index]=max(pointsA,pointsB);
    }
public:
    long long mostPoints(vvi& questions) {
        SZ=questions.size();
        memset(dp,-1,(SZ+1)*sizeof(ll));
        return fn(questions,0);
    }
};