class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int s=9;
        int iter=9;
        if(n==0)return 1;
        if(n==1)return 10;
        for(int i=1;i<n;i++)
        {
            s*=iter;
            iter--;
        }//end of for. 
        s+=countNumbersWithUniqueDigits(n-1);
        return s;
    }
};