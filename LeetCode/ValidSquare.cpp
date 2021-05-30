typedef vector<int> vi;
class Solution {
    int dist(vi& a,vi& b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12=dist(p1,p2);
        int d13=dist(p1,p3);
        int d14=dist(p1,p4);
        int d23=dist(p2,p3);
        int d24=dist(p2,p4);
        int d34=dist(p3,p4);
        vi arr({d12,d13,d14,d23,d24,d34});
        sort(arr.begin(),arr.end());
        int cmp=arr[0];
        for(int i=1;i<4;i++)
            if(cmp!=arr[i])return false;
        return (2*cmp==arr[4] && 2*cmp==arr[5] && cmp);
    }
};