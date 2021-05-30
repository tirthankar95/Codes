class Solution {
public:
    vector<int> constructRectangle(int area) {
        int limit=sqrt(area);
        int i;
        for(i=limit;i>=1;i--)
        {
            if(area%i==0)break;
        }
        return {area/i,i};
    }
};