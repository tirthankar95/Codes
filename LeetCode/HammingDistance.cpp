class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=x^y;
        int cnt=0,iter=1;
        while(iter<=31)
        {
            if(ans&(0x1))cnt++;
            ans=ans>>1;
            iter+=1;
        }
        return cnt;
    }
};