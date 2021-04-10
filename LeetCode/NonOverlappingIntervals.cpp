typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    static bool myCompare(const vi& a,const vi& b)
    {
        if(a[1]==b[1])return a[0]<b[0];
        else return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),myCompare);
        int n=intervals.size();
        if(!n)return 0;
        vi temp=intervals[0];int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(temp[1]<=intervals[i][0])
                temp=intervals[i];
            else cnt++;
        }
        return cnt;
    }
};