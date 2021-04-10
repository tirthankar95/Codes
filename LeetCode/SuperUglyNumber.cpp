class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)return 1;
        int sz=primes.size();
        vector<int> ptr(sz,0);
        vector<int> rSol(n,0);
        rSol[0]=1;int cnt=1;
        while(cnt<n)
        {
            int mi=INT_MAX,saveIndex;
            for(int i=0;i<sz;i++)
            {
                if(mi>rSol[ptr[i]]*primes[i])
                {
                    mi=rSol[ptr[i]]*primes[i];
                    saveIndex=i;
                }
            }//end of for-loop. 
            rSol[cnt]=mi;
            for(int i=0;i<sz;i++)
                if(mi==rSol[ptr[i]]*primes[i])
                    ptr[i]++;
            cnt++;
        }//end of while.
        return rSol[n-1];
    }
};
