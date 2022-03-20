typedef vector<int> vi;
class Solution {
    int n;
    int fn(vi& tops,vi& bottoms,int element){
        int i,top=0,bottom=0;
        for(i=0;i<n;i++)
        {
            if(element!=tops[i] && element!=bottoms[i])
                break;
            if(tops[i]==element)top++;
            if(bottoms[i]==element)bottom++;
        }
        if(i==n)
            return min(n-top,n-bottom);
        return -1;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        n=tops.size();
        assert(n==bottoms.size());
        int res=fn(tops,bottoms,tops[0]);
        if(res==-1)
            res=fn(tops,bottoms,bottoms[0]);
        return res;
    }
};