typedef vector<int> vi;
const int mxSize=60;
int modArr[mxSize];

class Solution {
public:
    int numPairsDivisibleBy60(vi& time) {
        int n=time.size();
        memset(modArr,0,mxSize*sizeof(int));
        for(int i=0;i<n;i++)
            modArr[time[i]%60]++;
        int res=modArr[0]*(modArr[0]-1)/2;
        res+=modArr[30]*(modArr[30]-1)/2;
        for(int i=1;i<=29;i++)
            res+=modArr[i]*modArr[60-i];
        return res;
    }
};