const int MOD=1e9+7;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        int nH=hC.size();
        int mxH=0,lbH=0;
        sort(hC.begin(),hC.end());
        for(int i=0;i<nH;i++){
            mxH=max(mxH,hC[i]-lbH);
            lbH=hC[i];
        }
        mxH=max(mxH,h-lbH);
        int nV=vC.size();
        int mxV=0,lbV=0;
        sort(vC.begin(),vC.end());
        for(int i=0;i<nV;i++){
            mxV=max(mxV,vC[i]-lbV);
            lbV=vC[i];
        }
        mxV=max(mxV,w-lbV);
        long long prod=(long long)mxH*(long long)mxV;
        return prod%MOD;
    }
};