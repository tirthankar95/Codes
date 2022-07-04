//#define DBG
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> carr(n,1);
        for(int i=1;i<n;i++)
            if(ratings[i-1]<ratings[i])
                carr[i]=1+carr[i-1];
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                carr[i]=max(carr[i],1+carr[i+1]);
#ifdef DBG
        for(int i=0;i<n;i++)
            cout<<carr[i]<<" ";
        cout<<endl;
#endif
        int res=0;
        for(int i=0;i<n;i++)res+=carr[i];
        return res;
    }
};