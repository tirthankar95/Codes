typedef vector<int> vi;
const int mxSize=1e5+1;
int stack_[mxSize];
int top;

class Solution {
public:
    vi dailyTemperatures(vi& temp) {
        int n=temp.size();  
        vi sol(n);top=-1;
        stack_[++top]=n-1;sol[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            while(top>-1 && temp[i]>=temp[stack_[top]]){
                    top--;
            }
            sol[i]=(top==-1)?0:stack_[top]-i;
            stack_[++top]=i;
        }//end of for. 
        return sol;
    }
};