typedef long long ll;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        ll shift=1;int i;
        int ans=0;
        while(left)
        {
            for(i=31;i>=0;i--)
                if(left&(shift<<i))break;
            int mid=(1<<i)<<1;
            if(left<=mid && mid<=right)return ans;
            else{
                ans|=(1<<i);
                left&=~(1<<i);
                right&=~(1<<i);
                //cout<<left<<" "<<right<<endl;
            }
        }
        return ans;
    }
};