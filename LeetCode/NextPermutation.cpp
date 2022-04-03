//#define DBG
typedef vector<int> vi;
int temp[101];

class Solution {
#ifdef DBG
    void print(vi& nums){
        int n=nums.size();
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
#endif
    void merge(vi& nums,int lb,int ub){
        int f=lb,fe=(lb+ub)/2;
        int s=1+fe,se=ub;
        int k=0;
        while(f<=fe && s<=se){
            if(nums[f]<=nums[s])
                temp[k++]=nums[f++];
            else
                temp[k++]=nums[s++];
        }//
        while(f<=fe){
            temp[k++]=nums[f++];
        }
        while(s<=se){
            temp[k++]=nums[s++];
        }
        for(int i=lb;i<=ub;i++)
            nums[i]=temp[i-lb];   
    }
    void msort(vi& nums,int lb,int ub){
        if(lb<ub){
            int mid=(lb+ub)/2;
            msort(nums,lb,mid);
            msort(nums,mid+1,ub);
            merge(nums,lb,ub);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i;
        if(n==1)return;
        for(i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;
#ifdef DBG
        cout<<"index["<<i<<"]\n";
#endif
        if(i==-1){
            msort(nums,0,n-1);
            return;
        }
        msort(nums,i+1,n-1);
#ifdef DBG
        print(nums);
#endif
        int index=n-1;
        for(int j=n-1;j>i;j--){
            if(nums[i]<nums[j])
                index=j;
            else break;
        }
#ifdef DBG
        cout<<"index["<<index<<"]\n";
#endif
        swap(nums[i],nums[index]);
    }//end of fn.
};