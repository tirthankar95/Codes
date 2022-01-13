typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int findMinArrowShots(vvi& points) {
        int sz=points.size();
        sort(points.begin(),points.end());
        vi run=points[0];int cnt=1;
        for(int i=1;i<sz;i++){
            if(run[1]>=points[i][0])
            {
                run[0]=points[i][0];
                run[1]=min(run[1],points[i][1]);
            }
            else{
                cnt++;
                run=points[i];
            }
        }
        return cnt;
    }
};