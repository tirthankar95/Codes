const int mxSize=129;
struct node{
    char ch;
    int freq;
};
node mapped[mxSize];
class Solution {
    void mergeD(int lb,int mid,int ub)
    {
        int f=lb;int s=mid+1;
        node dummy[ub-lb+1];
        int cnt=0;
        while(f<=mid && s<=ub)
        {
            if(mapped[f].freq<mapped[s].freq)
                dummy[cnt++]=mapped[s++];
            else dummy[cnt++]=mapped[f++];
        }
        while(f<=mid)
            dummy[cnt++]=mapped[f++];
        while(s<=ub)
            dummy[cnt++]=mapped[s++];
        for(int i=lb;i<=ub;i++)
            mapped[i]=dummy[i-lb];
    }
    void mSort(int lb,int ub)
    {
        if(lb<ub)
        {
            int mid=(lb+ub)/2;
            mSort(lb,mid);
            mSort(mid+1,ub);
            mergeD(lb,mid,ub);
        }
    }
public:
    string frequencySort(string s) {
        int n=s.length();
        memset(mapped,0,sizeof(mapped));
        for(int i=0;i<n;i++)
        {
            node& tmp=mapped[(int)(s[i]-'0')];
            tmp.ch=s[i];
            tmp.freq++;
        }
        mSort(0,mxSize-1);
        string ans=s;
        int cnt=0;
        for(int i=0;i<mxSize;i++)
        {
            for(int j=0;j<mapped[i].freq;j++)
                ans[cnt++]=mapped[i].ch;
        }
        return ans;
    }
};