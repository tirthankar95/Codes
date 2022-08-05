class Solution {
public:
    int mirrorReflection(int p, int q) {
        int res2,res0;
        for(int i=1;i<=q;i+=2){
            res2=((i*p)%q==0)?(i*p)/q:1;
            if(res2%2==0)return 2;
            res0=(((i+1)*p)%q==0)?((i+1)*p)/q:0;
            if(res0%2==1)return 0;
        }
        return 1;
    }
};