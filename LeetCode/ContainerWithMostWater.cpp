class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=INT_MIN;
        int lb=0;int ub=height.size()-1;
        while(lb<ub){
            mx=max(mx,min(height[lb],height[ub])*(ub-lb));
            if(height[lb]<height[ub])lb++;
            else ub--;
        }
        return mx;
    }
};