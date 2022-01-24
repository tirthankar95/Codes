class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isUpper=(word[0]>='a' && word[0]<='z')?false:true;
        bool isLower=(word[0]>='a' && word[0]<='z')?true:false;
        bool isFirstUpper=(word[0]>='a' && word[0]<='z')?false:true;
        int n=word.size();
        for(int i=1;i<n;i++){
            if(word[i]>='a' && word[i]<='z')
                isUpper=false;
            else{
                isFirstUpper=false;
                isLower=false;
            }
        }
        return (isUpper|isLower|isFirstUpper);
    }
};