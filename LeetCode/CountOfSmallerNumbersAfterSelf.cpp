typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int mxSize=1e5+1;
vii numN(mxSize);

class Solution {
    void merge(vii& num,int lb,int mid,int ub,vi& freq){
        int left=lb,right=mid+1;
        int cnt=0;
        while(left<=mid && right<=ub){
            if(num[left].first>num[right].first)
            {
                freq[num[left].second]+=(ub-right+1);
                numN[cnt++]=num[left++];
            }
            else
                numN[cnt++]=num[right++];
        }
        while(left<=mid)
            numN[cnt++]=num[left++];
        while(right<=ub)
            numN[cnt++]=num[right++];
        for(int i=lb;i<=ub;i++)
            num[i]=numN[i-lb];
    }
    void msort(vii& num,int lb,int ub,vi& freq){
        if(lb>=ub)return;
        int mid=(lb+ub)/2;
        msort(num,lb,mid,freq);
        msort(num,mid+1,ub,freq);
        merge(num,lb,mid,ub,freq);
    }
public:
    vector<int> countSmaller(vi& nums) {
        int n=nums.size();
        vi freq(n,0);
        vii num(n);
        for(int i=0;i<n;i++){
            num[i].first=nums[i];
            num[i].second=i;
        }
        msort(num,0,n-1,freq);
        return freq;
    }
};