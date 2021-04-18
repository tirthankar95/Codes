class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=s.size();
        int cnt=0;
        int lb=g.size()-1;
        for(int i=n-1;i>=0;i--)
        {
            while(lb>=0 && g[lb]>s[i])lb--;
            if(lb>=0 && g[lb]<=s[i])cnt++,lb--;
            if(lb<0)break;
        }
        return cnt;
    }
};