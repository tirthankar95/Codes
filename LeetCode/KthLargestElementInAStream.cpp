class KthLargest {
    priority_queue<int> pQ;
    int sz;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        sz=0;
        this->k=k;
        for(int i=0;i<min(n,k);i++)
            pQ.push(-1*nums[i]),sz++;
    }
    int add(int val) {
        if(sz>=k && -1*pQ.top()>=val)return -1*pQ.top();
        if(sz>=k){
            pQ.pop();
            sz--;
        }
        pQ.push(-1*val);
        sz++;
        return -1*pQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */