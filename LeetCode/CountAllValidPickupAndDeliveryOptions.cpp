typedef long long ll;
const int MOD=1e9+7;
const int mxSize=501;
bool isFirst=true;
ll fact[mxSize];
ll tempAns[mxSize];

class Solution {
    void init(){
        fact[0]=tempAns[0]=1;
        for(int i=1;i<mxSize;i++)
            fact[i]=((ll)i*fact[i-1])%MOD;
        int iter=1;
        for(int i=1;i<mxSize;i++){
            tempAns[i]=((ll)iter*tempAns[i-1])%MOD;
            iter+=2;
        }
    }
public:
    int countOrders(int n) {
        if(isFirst){
            init();     
            isFirst=false;
        }
        ll res=tempAns[n]*fact[n];
        return res%MOD;
    }
};
