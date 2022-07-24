class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int s_y=0;int s_x=c-1;
        while(s_y<r && s_x>=0){
            if(matrix[s_y][s_x]>target)
                s_x-=1;
            else if(matrix[s_y][s_x]<target)
                s_y+=1;
            else 
                return true;
        }
        return false;
    }
};