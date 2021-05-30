typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class Solution {
public:
    int leastBricks(vvi& wall) {
        unordered_map<ll,int> hashMap;
        int n=wall.size();
        vector<ll> iterate;ll cum=0;
        for(int i=0;i<n;i++)
        {
            cum=0;
            int m=wall[i].size();
            for(int j=0;j<m;j++)
            {
                cum+=(ll)wall[i][j];
                if(j!=m-1)
                {
                    if(hashMap.find(cum)==hashMap.end())
                    {
                        hashMap[cum]=1;
                        iterate.push_back(cum);
                    }
                    else hashMap[cum]++;
                }
            }//end of for-j.
        }//end of for-i.
        int N=iterate.size();
        int mi=n;
        for(int i=0;i<N;i++)
            mi=min(mi,n-hashMap[iterate[i]]);
        return mi;
    }
};