const int dim1=211;
const int dim2=(1<<20)-1;
char dp[dim1][dim2];

class Solution {
    int maxChoosableInteger;
    int desiredTotal;
    int mask;
    bool fn(int n,int playa) // returns true if current state is winnable. 
    {      
        if(n<0)return false;
        if(n==0 || ( n<=maxChoosableInteger && !(bool)(mask&(1<<(n-1))) ))return true;
        if(dp[n][mask]!=-1)
            return dp[n][mask];
        int tmp,j;
        for(int i=1;i<=maxChoosableInteger;i++)
        {
            j=i-1;
            if((bool)(mask&(1<<j)))continue;
            mask|=(1<<j);
            tmp=fn(n-i,1-playa);
            mask&=~(1<<j);
            if(tmp==false)
            {
                return dp[n][mask]=true;
            }
        }
        return dp[n][mask]=false;    
    }// end of fn.
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((maxChoosableInteger*(maxChoosableInteger+1)/2)<desiredTotal)return false;
        this->maxChoosableInteger=maxChoosableInteger;
        this->desiredTotal=desiredTotal;
        int sz=(1<<maxChoosableInteger)-1;
        mask=0;
        for(int i=1;i<=desiredTotal;i++)
            memset(dp[i],-1,sizeof(char)*sz);
        return fn(desiredTotal,0);
    }
};