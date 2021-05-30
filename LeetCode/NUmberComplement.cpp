class Solution {
public:
    int findComplement(int num) {
        if(num==0)return 1;
        int shift=0,ans=0;
        while(num)
        {
            int bit=(bool)(num&0x1);
            num>>=1;
            ans|=(1-bit)<<shift;
            shift++;
        }//end of while.
        return ans;
    }
};