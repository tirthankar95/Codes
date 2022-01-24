typedef long long ll;
const int MOD=1e9+7;

class Solution {
public:
    int numberOfWays(string corridor) {
        int n=corridor.length();
        int sCnt=0,gCnt=0,temp;
        int i=0;ll res=1;
        while(i<n){
            if(corridor[i]=='S')
                sCnt++,gCnt++;
            if(sCnt==2 && i<n-1){
                temp=0,sCnt=0;
                while(i<n-1 && corridor[++i]=='P')temp++;
                if(corridor[i]=='S')
                    res=(res*(ll)(temp+1))%MOD;
                i--;
            }
            i++;
        }//end of while.
        return ((gCnt==0 || gCnt%2)?0:res%MOD);
    }
};