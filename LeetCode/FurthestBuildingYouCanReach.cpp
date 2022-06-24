typedef long long ll;
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<ll> pq;int pqLen=0;
        ll sum=0,sum_ladder=0,diff;
        for(int i=1;i<n;i++){
            if(heights[i-1]<heights[i])
            {
                diff=(ll)(heights[i]-heights[i-1]);
                sum+=diff;
                if(ladders && (pqLen<ladders || -1*pq.top()<diff)){
                    if(pqLen==ladders){
                        sum_ladder+=pq.top();
                        pq.pop();
                        pqLen--;
                    }
                    sum_ladder+=diff;
                    pq.push(-1*diff);
                    pqLen++;
                }//ladder
                if((sum-sum_ladder)>bricks)return i-1;
            }
        }//
        return n-1;
    }
};
