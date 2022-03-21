typedef vector<int> vi;
const int mxSize=128;
int latest[mxSize];

class Solution {
public:
    vi partitionLabels(string s) {
        int n=s.length();
        vi sol;
        for(int i=0;i<n;i++)
            latest[s[i]]=i;
        int lb=0;
        int ub,start;
        while(lb<n)
        {
            ub=latest[s[lb]],start=lb;
            while(lb<ub){
                ub=max(ub,latest[s[++lb]]);
            }
            sol.push_back(ub-start+1);
            lb++;
        }
        return sol;
    }//end of fn.
};