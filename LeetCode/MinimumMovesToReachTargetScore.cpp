class Solution {
    int fn(int target,int maxDoubles){
        /*
        if(maxDoubles<0 || target<1)return INT_MAX;
        if(target==1)return 0;
        if(dp.find(target)!=dp.end()){
            return dp[target];
        }
        if(target%2==0)
            dp[target]=1+min(fn(target/2,maxDoubles-1),fn(target-1,maxDoubles));
        else 
            dp[target]=1+fn(target-1,maxDoubles);
        return dp[target];
        */
        if(maxDoubles<0 || target<1)return INT_MAX;
        if(target==1)return 0;
        if(target%2==0){
             if(maxDoubles)
                 return 1+fn(target/2,maxDoubles-1);
            else 
                return target-1;
        }
        else{
            if(maxDoubles)
                return 2+fn((target-1)/2,maxDoubles-1);
            else 
                return target-1;
        }
    }
public:
    int minMoves(int target, int maxDoubles) {
        return fn(target,maxDoubles);
    }
};