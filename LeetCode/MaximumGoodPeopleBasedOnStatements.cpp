typedef vector<int> vi;
class Solution {
    int mx,n;
    int countOnes(int flag){
        int count=0;
        while(flag){
            flag&=(flag-1);
            count++;
        }
        return count;
    }
    bool isValid(int flag,vector<vi>& statements){
        for(int i=0;i<n;i++){
            if(flag&(1<<i)){
                for(int j=0;j<n;j++){
                    if(statements[i][j]!=2 && statements[i][j]!=(bool)(flag&(1<<j)))
                        return false;
                }//end of for-j.
            }
        }//end of for-i.
        return true;
    }
public:
    int maximumGood(vector<vi>& statements) {
        n=statements.size();
        int flag=(1<<n)-1;
        mx=0;
        for(int i=1;i<=flag;i++){
            if(isValid(i,statements))
                mx=max(mx,countOnes(i));
        }
        return mx;
    }
};