bool isFirst=true;
const int mxSize=38;
typedef long long ll;
ll T[mxSize];

class Solution {
public:
    int tribonacci(int n) {
        if(isFirst){
            isFirst=false;
            T[0]=0,T[1]=1,T[2]=1;
            for(int i=3;i<mxSize;i++)
                T[i]=T[i-1]+T[i-2]+T[i-3];
        }
        return T[n];
    }
};