typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
    int R,C;
public:
    int kthSmallest(vvi& matrix, int k) {
        R=matrix.size();
        C=matrix[0].size();
        vi ptr(R,0);
        int lb=matrix[0][0];
        int ub=matrix[R-1][C-1];
        while(lb<=ub)
        {
            int mid=(lb+ub)/2;
            int ktmp=0;
            for(int i=0;i<R;i++)
            {
                int lb_=0;int ub_=C-1;
                while(lb_<=ub_)
                {
                    int mid_=(lb_+ub_)/2;
                    if(matrix[i][mid_]<mid)lb_=mid_+1;
                    else ub_=mid_-1;
                }
                ktmp+=(ub_+1);
            }//end of for-loop.     
            if(ktmp<k)lb=mid+1;
            else ub=mid-1;
        }//end of while.
        return ub;
    }
};