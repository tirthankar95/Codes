class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mxProd=nums[0];
        int pos=1,neg=1,tmp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos=pos*nums[i];
                neg=neg*nums[i];
                mxProd=max(mxProd,pos);
            }
            else if(nums[i]<0)
            {
                tmp=pos;
                if(neg<0){         
                    pos=neg*nums[i];
                    mxProd=max(mxProd,pos);
                }
                else
                    pos=1;
                neg=tmp*nums[i];
            }//end of else.
            else{
                mxProd=max(mxProd,nums[i]);
                pos=1,neg=1;
            }
        }//end of for.
        return mxProd;
    }
};