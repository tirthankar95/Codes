// USING mutiset IS ALSO A SOLUTION.
typedef vector<int> vi;
typedef vector<vi> vvi;
const int mxSize=1e4+1;
vvi temp(mxSize);
//retruns true if a is strictly greater than b.
inline bool compare(vi& a,vi& b){
    return ((a[0]*a[0]+a[1]*a[1])>(b[0]*b[0]+b[1]*b[1]));
}
class Solution {
    void mSort(vvi& arr,int lb,int ub){
        int mid=(lb+ub)/2;
        if(lb<ub){
            mSort(arr,lb,mid);
            mSort(arr,mid+1,ub);
            {// merge function without making excess function calls.
                int fptr=lb,sptr=mid+1,iter=0;
                while(fptr<=mid && sptr<=ub){
                    if(compare(arr[fptr],arr[sptr]))temp[iter++]=arr[sptr++];
                    else temp[iter++]=arr[fptr++];
                }
                while(fptr<=mid)temp[iter++]=arr[fptr++];
                while(sptr<=ub)temp[iter++]=arr[sptr++];
                for(int i=0;i<iter;i++)arr[lb+i]=temp[i];                
            }// merge function without making excess function calls.
        }
    }
public:
    vvi kClosest(vvi& points, int k) {
        mSort(points,0,points.size()-1);
        points.resize(k);
        return points;
    }
};