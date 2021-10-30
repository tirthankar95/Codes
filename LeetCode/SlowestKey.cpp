typedef long long ll;
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n=releaseTimes.size();
        for(int i=n-1;i>=1;i--)
            releaseTimes[i]-=releaseTimes[i-1];
        int m=keysPressed.length();
        int mx=0;char mxCh;
        for(int i=0;i<m;i++)
        {
            if(mx<releaseTimes[i] || (mx==releaseTimes[i] && mxCh<keysPressed[i]))
            {
                mxCh=keysPressed[i];
                mx=releaseTimes[i];
            }
        }
        return mxCh;
    }
};