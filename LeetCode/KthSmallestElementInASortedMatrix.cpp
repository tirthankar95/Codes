typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
    int r,c;
    int find(vvi& matrix,int element){
        int lb,ub,mid,rank=0;
        for(int i=0;i<r;i++){
            lb=0,ub=c-1;
            while(lb<=ub){
                mid=(lb+ub)/2;
                if(element<=matrix[i][mid])ub=mid-1;
                else if(element>matrix[i][mid])lb=mid+1;
            }
            rank+=(ub+1);
        }
        return rank;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lb=matrix[0][0];
        r=matrix.size(),c=matrix[0].size();
        int ub=matrix[r-1][c-1];
        int mid,rank,ans;
        k--;
        while(lb<=ub){
            mid=(lb+ub)/2;
            rank=find(matrix,mid);
            //cout<<mid<<" "<<rank<<endl;
            if(rank>k)ub=mid-1;
            else if(rank<k)lb=mid+1;
            else{
                ans=mid;
                lb=mid+1;
            }
        }//
        return ((lb<=ub)?ans:ub);
    }
};