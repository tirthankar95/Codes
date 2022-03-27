typedef pair<int,int> ii;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r=mat.size();
        int c=mat[0].size();
        vector<ii> array(r);
        for(int i=0;i<r;i++){
            int count=0;
            for(int j=0;j<c;j++){
                if(mat[i][j]==0)break;
                count++;
            }
            array[i]=ii(count,i);
        }
        sort(array.begin(),array.end());
        vector<int> result(k);
        for(int i=0;i<k;i++)
            result[i]=array[i].second;
        return result;
    }
};