bool gCalled=false;
const int mxSize=1690;
const int N=1e7+1;
int Arr[N];
int ugly[mxSize];

class Solution {
    void seive()
    {
        if(gCalled)return;
        Arr[1]=1;
        for(int i=2;i<N;i++)
        {
            if(Arr[i]!=0)continue;
            if(!(i==2 || i==3 || i==5))Arr[i]=2;
            else Arr[i]=1;
            for(int j=2*i;j<N;j+=i)
                Arr[j]=Arr[i];
        }
        int cnt=0;
        for(int i=0;i<N;i++)
            if(Arr[i]==1)ugly[cnt++]=i;
    }
public:
    int nthUglyNumber(int n) {
        seive();
        return ugly[n-1];
    }
};