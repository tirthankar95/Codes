class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n)return false;
        while(n!=1){
            if(n&1)return false;
            else n>>=1;
        }
        return true;
    }
};