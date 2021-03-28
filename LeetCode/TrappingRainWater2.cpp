#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

class OBJ{
public:    
    int i;
    int j;
    int h;
    OBJ(int i,int j,int h)
    {
        this->i=i;
        this->j=j;
        this->h=h;
    }
};
struct CompareHeight{
    bool operator()(const OBJ& o1,const OBJ& o2)
    {
        return o1.h>o2.h;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r=heightMap.size();
        int c=heightMap[0].size();
        int ni,nj,ans=0;
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        priority_queue<OBJ,vector<OBJ>,CompareHeight> pq;
        for(int j=0;j<c;j++)
        {
            pq.push(OBJ(0,j,heightMap[0][j]));
            pq.push(OBJ(r-1,j,heightMap[r-1][j]));        
            vis[0][j]=true;
            vis[r-1][j]=true;
        }
        for(int i=1;i<r-1;i++)
        {
            pq.push(OBJ(i,0,heightMap[i][0]));
            pq.push(OBJ(i,c-1,heightMap[i][c-1]));
            vis[i][0]=true;
            vis[i][c-1]=true;
        }
        while(!pq.empty())
        {
            OBJ src=pq.top();
            pq.pop();
            for(int i=0;i<4;i++)
            {
                ni=src.i+dir[i][0];
                nj=src.j+dir[i][1];
                if(ni>=0 && nj>=0 && ni<r && nj<c && !vis[ni][nj])
                {
                    vis[ni][nj]=true;
                    ans+=max(0,src.h-heightMap[ni][nj]);
                    pq.push(OBJ( ni,nj,max(src.h,heightMap[ni][nj]) ));
                }
            }
        }//end of PQ.
        return ans;
    }
};

//Driver function.
int main(){
    freopen("ip1.txt", "r", stdin); // redirects standard input
    freopen("op1.txt", "w", stdout); // redirects standard output
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        vvi arr(r,vi(c));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>arr[i][j];
        cout<<obj.trapRainWater(arr)<<endl;
    }//end of while. 
    return 0;
}