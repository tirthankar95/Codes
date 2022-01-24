typedef long long ll;
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n=differences.size();
        ll min_=0,max_=0,cSum=0;
        for(int i=0;i<n;i++)
        {
            cSum+=(ll)differences[i];
            min_=min(min_,cSum);
            max_=max(max_,cSum);
        }//end of for.
        ll res=(upper-lower)-(max_-min_)+(ll)1;
        return ((res<=0)?0:res);
    }
};