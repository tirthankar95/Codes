//#define DBG
typedef vector<int> vi;

class Solution {
    int hcf(int a,int b){
        if(b==0)return a;
        return hcf(b,a%b);
    }
#ifdef DBG
    void print(vi& nums){
        int n=nums.size();
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        cout<<endl;
    }
#endif
public:
    void rotate(vector<int>& nums, int k) {
        /*
            shifts required <- HCF(n,k)
            No. of element in correct position after 1 shift <- n/HCF(n,k)
        */
        int n=nums.size();
        int shifts=hcf(n,k);
        int change=n/shifts;
        int temp,temp1,i_;
        for(int i=0;i<shifts;i++){
            temp1=nums[i],i_=i;
            for(int j=1;j<=change;j++){
                temp=nums[(i_+k)%n];
                nums[(i_+k)%n]=temp1;
                i_=(i_+k)%n;
                temp1=temp;
            }
# ifdef DBG
            print(nums);
#endif
        }//end of outer for.
    }
};