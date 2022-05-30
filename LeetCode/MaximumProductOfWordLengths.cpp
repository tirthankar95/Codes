struct node{
    unsigned int mask;
    int len;
};
class Solution {
    unsigned int getMask(string s){
        int n=s.length();
        int mask=0;
        for(int i=0;i<n;i++)
            mask=mask|(1<<(int)(s[i]-'a'));
        return mask;
    }
public:
    int maxProduct(vector<string>& words) {
        int n;
        vector<node> arr(n=words.size());
        for(int i=0;i<n;i++)
        {
            arr[i].mask=getMask(words[i]);
            arr[i].len=words[i].length();
        }//end of for. 
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if((arr[i].mask&arr[j].mask)==0)
                    res=max(res,arr[i].len*arr[j].len);
        }
        return res;
    }
};