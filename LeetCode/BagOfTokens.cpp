class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;int res=0;
        int n=tokens.size();
        int lb=0,ub=n-1;
        while(lb<=ub && score>=0)
        {
            if(power>=tokens[lb]){
                score++;
                power-=tokens[lb++];
            }
            else{
                score--;
                power+=tokens[ub--];
            }
            res=max(res,score);
        }
        return res;
    }
};