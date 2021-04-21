typedef vector<int> vi;
typedef vector<vi> vvi;
namespace __local__
{
    int distSq(vvi&points,int i,int j)
    {
        return pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2);
    }
}

class Solution {
public:
    int numberOfBoomerangs(vvi& points) {
        int n=points.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> hashMap;
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                int tmp=__local__::distSq(points,i,j);
                ans+=2*hashMap[tmp];
                hashMap[tmp]++;
            }
        }
        return ans;
    }
};