typedef long long ll;
bool firstCall=true;
const int N=5;
const int mxSize=50;
ll res[mxSize+1];    
//#define DBG 

class Solution {
    void init(){
        res[0]=1;
        for(int i=1;i<=mxSize;i++)
            res[i]=(res[i-1]*(N+(i-1)))/i;
#ifdef DBG
        for(int i=1;i<=mxSize;i++)
            cout<<i<<" ~ "<<res[i]<<endl;
#endif 
    }
public:
    int countVowelStrings(int n) {
        if(firstCall){
            init();
            firstCall=false;
        }
        return res[n];
    }
};