class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)return 1;
        int res=0;int i=n,iter=0;
        while(i){
            iter++;
            i>>=1;
        }
        i=1;
        while(iter--){
            if(!(n&i))
                res|=i;
            i<<=1;
        }
        return res;
    }
};