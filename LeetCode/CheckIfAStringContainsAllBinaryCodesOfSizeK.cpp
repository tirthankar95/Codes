class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        int total=(1<<k);
        if((n-k+1)<total)return false;
        unordered_map<int,bool> found;
        int no=0;
        for(int i=0;i<k;i++)
            no=(no<<1)|((int)(s[i]-'0'));
        found[no]=true;total--;
        int mask=~(1<<k);
        
        for(int i=k;i<n;i++){
            no=(no<<1)|((int)(s[i]-'0'));
            no=no&mask;
            if(found.find(no)==found.end()){
                found[no]=true;
                total--;
            }
        }//end of for. 
        return (total==0);
    }
};