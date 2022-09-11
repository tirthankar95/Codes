typedef vector<int> vi;

class Solution {
public:
    int numberOfWeakCharacters(vector<vi>& p) {
        sort(p.begin(),p.end());
        int n=p.size(),count=0;
        int xc,yc,yp;
        xc=p[n-1][0];yc=p[n-1][1];yp=INT_MIN;
        for(int i=n-2;i>=0;i--){
            if(p[n-1][0]==p[i][0])continue;
            if(yc<p[i][1] && yp<p[i][1]){
                yp=yc;
                xc=p[i][0];yc=p[i][1];
                continue;
            }
            if((xc>p[i][0] && yc>p[i][1])||yp>p[i][1])
                count++;
        }
        return count;
    }
};