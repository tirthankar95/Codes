typedef vector<int> vi;
typedef vector<vi> vvi;
// 0 -> linear.
// 1 -> anti-clockwise.
// 2 -> clockwise.
class Solution {
    int orientation(vi& a,vi& b,vi& c){
        if((c[1]-b[1])*(b[0]-a[0])>(b[1]-a[1])*(c[0]-b[0]))return 1;
        else if((c[1]-b[1])*(b[0]-a[0])<(b[1]-a[1])*(c[0]-b[0]))return 2;
        else return 0;
    }
    int dist(vi& a,vi& b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
public:
    vvi outerTrees(vvi& trees) {
        vvi ans;        
        int n=trees.size();
        if(n<3)return trees;
        int mi_x=INT_MAX; int mi_x_id;
    // First element.
        for(int i=0;i<n;i++)
        {
            if(trees[i][0]<mi_x)
            {
                mi_x=trees[i][0];
                mi_x_id=i;
            }
        }//end of for-i.
        ans.push_back(trees[mi_x_id]);
        int f_indx=mi_x_id;int s_indx;
        vector<bool> vis(n,false);
        do{
            s_indx=(f_indx+1)%n;
            vis[f_indx]=true;
            for(int i=0;i<n;i++)
            {
                if(orientation(trees[f_indx],trees[s_indx],trees[i])==1)
                    s_indx=i;
            }//end of for-i.
            if(s_indx==mi_x_id)break;
            ans.push_back(trees[s_indx]);
            f_indx=s_indx;
        }while(true);
        int m=ans.size();
        for(int i=0;i<m;i++)
        {
            int i_=(i==m-1)?0:i+1;
            double slope=(double)(ans[i][1]-ans[i_][1])/(double)(ans[i][0]-ans[i_][0]);
            for(int j=0;j<n;j++)
            {
                if(vis[j])continue;
                double slope_=(double)(ans[i][1]-trees[j][1])/(double)(ans[i][0]-trees[j][0]);
                if(slope==slope_)
                {
                    vis[j]=true;
                    ans.push_back(trees[j]);
                }
            }
        }
        return ans;
    }
};