typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
class Solution {
    int part;
    int N;
    vll sol;
    void select(int start,int sum,vi& matchsticks,vector<bool>& isUsed)
    {
        if(sum==part)
        {
            ll flag=0;
            for(int i=0;i<N;i++)
            {
                if(isUsed[i])
                    flag|=((ll)1<<i);
            }
            sol.push_back(flag);
            return;
        }
        if(start>=N)return;
        isUsed[start]=true;
        select(start+1,sum+matchsticks[start],matchsticks,isUsed);
        isUsed[start]=false;
        select(start+1,sum,matchsticks,isUsed);
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        this->N=n;sol.clear();
        vector<bool> isUsed(n,false);
        ll sum=0;
        for(int i=0;i<n;i++)
            sum+=(ll)(matchsticks[i]);
        if(sum%4!=0)return false;
        this->part=sum/4;
        select(0,0,matchsticks,isUsed);
        int m=sol.size();
        ll tmp=((ll)1<<N)-1;
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if((sol[i]&sol[j])!=0)continue;
                for(int k=j+1;k<m;k++)
                {
                    if(((sol[i]|sol[j])&sol[k])!=0)continue;
                    for(int l=k+1;l<m;l++)
                        if(((sol[i]|sol[j]|sol[k])&sol[l])==0 && (sol[i]|sol[j]|sol[k]|sol[l])==tmp)
                            return true;
                }//end of for-k.
            }//end of for-j.
        }//end of for i.
        return false;
    }
};