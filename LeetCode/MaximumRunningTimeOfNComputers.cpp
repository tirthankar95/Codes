typedef long long ll;
typedef vector<int> vi;

class Solution {
    bool canFit(ll mid,ll n,vi& batteries){
        ll fptr=0,m=batteries.size();
        ll computer=1,timePerComputer=mid,lastLimit=0;
        ll batteriesTmp;
        while(computer<=n && fptr<m){
            if(timePerComputer>=batteries[fptr]){
                timePerComputer-=batteries[fptr++];
                if(timePerComputer==0){
                    computer++;
                    timePerComputer=mid;
                }
                lastLimit=mid-timePerComputer;
            }
            else{
                batteriesTmp=batteries[fptr++]-(mid-lastLimit);
                computer++;
                lastLimit=(batteriesTmp>=lastLimit)?lastLimit:batteriesTmp;
                timePerComputer=mid-lastLimit;   
            }
        }//end of while.
        return (computer>n);
    }
public:
    ll maxRunTime(int n, vi& batteries) {
        int m=batteries.size();
        sort(batteries.begin(),batteries.end());
        ll sum=0,lb=INT_MAX;
        for(int i=0;i<m;i++){
            sum=sum+(ll)(batteries[i]);
            lb=(lb>batteries[i])?batteries[i]:lb;
        }
        ll ub=sum/(ll)n;
        ll mid,ans;
        while(lb<=ub){
            mid=(lb+ub)/2;
            if(canFit(mid,n,batteries))
            {
                ans=mid;
                lb=mid+1;
            }
            else
                ub=mid-1;
        }
        return ans;
    }
};
/*
Solution 2: Binary Search C++
The idea is to check if we can run computers for m hours (n * m total hours). For that, we accumulate power from all batteries, taking no more than m from each. If we have enough power for n * m hours - we can run all our computers for m hours.
*/
long long maxRunTime(int n, vector<int>& bat) {
    long long l = 0, r = accumulate(begin(bat), end(bat), 0LL) / n;
    while (l < r) {
        long long m = (l + r + 1) / 2, minutes = 0;
        for (int b : bat)
            minutes += min((long long)b, m);
        if (minutes >= n * m)
            l = m;
        else
            r = m - 1;
    }
    return l;
}