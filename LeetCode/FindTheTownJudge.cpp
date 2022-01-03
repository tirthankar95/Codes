typedef vector<int> vi;
const int mxSize=1e3+1;
bool isPerson[mxSize];
int noOfTrustees[mxSize];

class Solution {
public:
    int findJudge(int n, vector<vi>& trust) {
        int m=trust.size();
        memset(isPerson,0,(n+1)*sizeof(bool));
        memset(noOfTrustees,0,(n+1)*sizeof(int));
        for(int i=0;i<m;i++)
        {
            isPerson[trust[i][0]]=true;
            noOfTrustees[trust[i][1]]+=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(isPerson[i]==false && noOfTrustees[i]==n-1)
                return i;
        }
        return -1;
    }
};