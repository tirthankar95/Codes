typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    // Returns biggest element less than target.
    // opt -> 0 row, opt -> 1 col.
    bool found_;
    int binSearch(vvi& matrix,int index,int lb,int ub,int target,int opt){
        int mid;
        if(opt==0){
            while(lb<=ub){
                mid=lb+(ub-lb)/2;
                if(matrix[index][mid]==target){
                    found_=true;
                    return mid;
                }
                if(matrix[index][mid]<target)
                    lb=mid+1;
                else 
                    ub=mid-1;
            }
            return ub;
        }
        else{
             while(lb<=ub){
                mid=lb+(ub-lb)/2;
                if(matrix[mid][index]==target){
                    found_=true;
                    return mid;
                }
                if(matrix[mid][index]<target)
                    lb=mid+1;
                else 
                    ub=mid-1;
            }
            return ub;           
        }
    }
public:
    bool searchMatrix(vvi& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int lbc=0,ubc=c-1;
        int lbr=0,ubr=r-1;
        found_=false;
        while(lbc<=ubc && lbr<=ubr)
        {
            ubc=binSearch(matrix,lbr,lbc,ubc,target,0);
            if(ubc==-1)return false;
            if(found_)return true;
            lbr=binSearch(matrix,ubc,lbr,ubr,target,1);
            if(lbr==-1)return false;
            if(found_)return true;
            lbr+=1;
        }
        return false;
    }
};