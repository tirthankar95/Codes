//#define DBG
class Solution {
#ifdef DBG
    void print(vector<int>& arr){
        int n=arr.size();
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
#endif
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r=triangle.size(),temp0,temp1,temp2,prev,m;
        vector<int> currRow(r,0);
        for(int i=0;i<r;i++){
            m=triangle[i].size();
            for(int j=0;j<m;j++){
                temp0=(j-1>=0)?currRow[j-1]:INT_MAX;
                temp1=(i>0 && j==m-1)?INT_MAX:currRow[j];
                temp2=triangle[i][j]+min(temp0,temp1);
                if(j-1>=0)
                    currRow[j-1]=prev;
                prev=temp2;
            }//end of j.
            currRow[m-1]=prev;
#ifdef DBG
            print(currRow);
#endif
        }//end of i.
        int mi=INT_MAX;
        for(int i=0;i<r;i++)
            mi=min(mi,currRow[i]);
        return mi;
    }
};