typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxSize=1e5+1;
vi temp(mxSize);

class Solution {
    int N;
    void merge(vi& arr,int lb,int mid,int ub){
        int fptr=lb,sptr=mid+1,iter=0;
        while(fptr<=mid && sptr<=ub){
            if(arr[fptr]<=arr[sptr])temp[iter++]=arr[fptr++];
            else temp[iter++]=arr[sptr++];
        }
        while(fptr<=mid)temp[iter++]=arr[fptr++];
        while(sptr<=ub)temp[iter++]=arr[sptr++];
        for(int i=0;i<iter;i++)arr[lb+i]=temp[i];
    }
    void mSort(vi& arr,int lb,int ub){
        if(lb<ub){
            int mid=lb+(ub-lb)/2;
            mSort(arr,lb,mid);
            mSort(arr,mid+1,ub);
            merge(arr,lb,mid,ub);
        }
    }
public:
    vvi minimumAbsDifference(vi& arr) {
        N=arr.size();
        mSort(arr,0,N-1);
        int minDiff=(arr[1]-arr[0]);
        for(int i=2;i<N;i++)
            minDiff=min(minDiff,arr[i]-arr[i-1]);
        vvi sol;
        for(int i=1;i<N;i++)
            if(minDiff==(arr[i]-arr[i-1]))
                sol.push_back(vi({arr[i-1],arr[i]}));
        return sol;
    }
};