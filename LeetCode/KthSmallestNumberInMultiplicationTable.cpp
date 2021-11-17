class Solution {
public:
    int findKthNumber(int R, int C, int k) {
        int lb=1;int ub=R*C;
        int rowLb,rowUb,mid;
        int cnt1,cnt0;
        while(lb<=ub)
        {
            mid=(lb+ub)/2;
            cnt1=0;cnt0=0;
            for(int row=1;row<=R;row++)
            {
                rowLb=row;rowUb=row*C;
                if(rowUb<=mid)cnt1+=C;
                else cnt1+=mid/row;
                if(rowUb<mid)cnt0+=C;
                else{
                    cnt0+=mid/row;
                    if(mid%row==0)cnt0-=1;
                }
            }
            if(cnt0<k && k<=cnt1)return mid; //very important criteria also holds for elements with 1 frequency. 
            if(cnt0<k && cnt1<k)lb=mid+1;
            else ub=mid-1;
        }//end of while.
        return mid;
    }
};