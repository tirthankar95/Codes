/*
LOGIC: 
Given that the sum is strictly increasing, the largest element in the target must be formed in the last step by adding the total sum in the previous step. 
Thus, we can simulate the process in a reversed way.
*/

typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll n=target.size(),prev_element,incr;
        priority_queue<ll> pq;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum=sum+(ll)target[i];
            pq.push((ll)target[i]);
        }
        while(!pq.empty()){
            if(pq.top()==1)break;
            incr=sum-pq.top();
            if(incr==1)//Special Case.
                prev_element=1;
            else if(incr>0 && pq.top()>incr)
                prev_element=pq.top()%incr;
            else 
                return false;
            sum-=(pq.top()-prev_element);
            pq.pop();
            pq.push(prev_element);
        }
        int cnt=0;
        while(!pq.empty()){
            if(pq.top()==1)cnt++;
            pq.pop();
        }
        return (cnt==n);
    }
};