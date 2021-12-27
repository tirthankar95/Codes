class Solution {
public:
    int findComplement(int num) {
        int res=0,k=0;
        while(num){
            res=((1^(num&1))<<k)|res;
            num>>=1;
            k++;
        }
        return res;
    }
};