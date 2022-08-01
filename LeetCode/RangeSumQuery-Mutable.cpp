typedef vector<int> vi;

class NumArray {
    int N,NS;
    vi arr,nums;
    int build(int ss,int se,int index){
        if(ss==se)return (arr[index]=nums[ss]);
        int mid=(ss+se)/2;
        arr[index]=build(ss,mid,2*index+1)+build(mid+1,se,2*index+2);
        return arr[index];
    }
    int sum(int ss,int se,int left,int right,int index){
        if(right<ss || se<left)return 0;
        if(left<=ss && se<=right)return arr[index];
        int mid=(ss+se)/2;
        return sum(ss,mid,left,right,2*index+1)+sum(mid+1,se,left,right,2*index+2);
    }
    void updateUtil(int ss,int se,int id,int index,int diff){
        if(id<ss || se<id || ss>se)return;
        if(ss==se){
            arr[index]+=diff;
            return;
        }
        arr[index]+=diff;
        int mid=(ss+se)/2;
        updateUtil(ss,mid,id,2*index+1,diff);
        updateUtil(mid+1,se,id,2*index+2,diff);        
    }
public:
    NumArray(vector<int>& NUMS) {
        nums=NUMS;
        N=nums.size();
        int x=(int)(ceil(log2(N))); 
        NS=2*(int)pow(2, x) - 1; 
        arr.resize(NS);
        build(0,N-1,0);
    }
    void update(int index, int val) {
        int diff=val-nums[index];
        nums[index]=val;
        updateUtil(0,N-1,index,0,diff);
    }
    
    int sumRange(int left, int right) {
        return sum(0,N-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */