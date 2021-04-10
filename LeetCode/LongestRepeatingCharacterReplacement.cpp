class Solution {
public:
    int characterReplacement(string S, int k) {
        int N=S.length();
        int mx=0;
        ////////
        if(k==0)
        {
            for(char ch='A';ch<='Z';ch++)
            {
                int lb=0,ub=0;
                while(ub<N)
                {
                    if(S[ub]==ch)ub++;
                    else{
                        mx=max(mx,ub-lb);
                        ub++;
                        lb=ub;
                    }
                }
                mx=max(mx,ub-lb);                
            }
            return mx;
        }// k==0
        for(char ch='A';ch<='Z';ch++)
        {
            int lb=0,ub=0,iterK=k;
            while(ub<N)
            {
                if(S[ub]==ch)ub++;
                else if(iterK>0)iterK--,ub++;
                else
                {
                    mx=max(mx,ub-lb);
                    while(S[lb]==ch)lb++;
                    while(S[lb]!=ch && lb<ub)lb++,iterK++;
                }
            }//end of while. 
            mx=max(mx,ub-lb);
        }//end of outer-for.
        return mx;
    }
};