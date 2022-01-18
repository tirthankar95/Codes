class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        int sz=ceil((float)n/(float)k);
        vector<string> res(sz);
        string blank;
        for(int i=0;i<k;i++)blank=blank+' ';
        int i,iter=0;
        for(i=0;i<n;i++){
            blank[i%k]=s[i];
            if(i%k==k-1){
                res[iter++]=blank;
            }
        }//end of for.
        while((i%k)!=0){
            blank[i%k]=fill;
            i++;
        }
        if(iter<=sz-1)
            res[iter++]=blank;
        return res;
    }
};