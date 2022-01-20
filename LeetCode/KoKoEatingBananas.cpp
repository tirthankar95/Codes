typedef vector<int> vi;
typedef long long ll;
class Solution {
    int n;
    inline ll timeTaken(int speed,vi& piles){
        ll time=0;
        for(int i=0;i<n;i++)
            time+=(piles[i]<=speed)?(ll)1:(ll)(piles[i]/speed+(bool)(piles[i]%speed));
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        n=piles.size();
        int lb=1,ub=piles[0];
        for(int i=1;i<n;i++)
            ub=max(ub,piles[i]);
        int mid,ans;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(timeTaken(mid,piles)<=h){
                ans=mid;
                ub=mid-1;
            }
            else 
                lb=mid+1;
        }//end of while. 
        return ans;
    }
};