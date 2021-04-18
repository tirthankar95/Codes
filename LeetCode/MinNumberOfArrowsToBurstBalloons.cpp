typedef vector<int> vi;

class Solution {
    static bool sortIntervals(const vi& a,const vi& b)
    {
        if(a[0]==b[0])return a[1]<b[1];
        else return a[0]<b[0];
    }
    void print(vector<vi>& points)
    {
        int n=points.size();
        for(int i=0;i<n;i++)
            cout<<"("<<points[i][0]<<","<<points[i][1]<<") ";
        cout<<endl;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),sortIntervals);
        //print(points);
        int ans=0;
        int lb=points[0][0],ub=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0]<=ub)
            {
                lb=points[i][0];
                ub=min(ub,points[i][1]);
                continue;
            }
            else
            {
                ans+=1;
                lb=points[i][0];
                ub=points[i][1];
            }
        }
        return ((n)?ans+1:ans);
    }
};