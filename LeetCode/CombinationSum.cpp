typedef vector<int> vi;

class Solution {
    vector<vi> fSol;
    int n;
    void fn(vi& candidates,int fptr,int target,vi& rSol){
        if(target==0){
            fSol.push_back(rSol);
            return;
        }
        if(fptr>=n || target<0)return;
        for(int i=fptr;i<n;i++)
        {
            rSol.push_back(candidates[i]);
            fn(candidates,i,target-candidates[i],rSol);
            rSol.pop_back();
        }
    }
public:
    vector<vi> combinationSum(vi& candidates, int target) {
        n=candidates.size();
        vi rSol;
        fn(candidates,0,target,rSol);
        return fSol;
    }
};