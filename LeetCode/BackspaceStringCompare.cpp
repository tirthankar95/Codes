//#define DBG
class Solution {
    int reduce(string& s){
        int n=s.length();
        int lb=0;
        for(int i=0;i<n;i++){
            if(s[i]!='#')
                swap(s[lb++],s[i]);
            else if(lb>0)
                lb--;
        }
        return lb;
    }
#ifdef DBG
    void print(string s,int n){
        for(int i=0;i<n;i++)
            cout<<s[i];
        cout<<endl;
    }
#endif
public:
    bool backspaceCompare(string s, string t) {
        int red_s=reduce(s);
        int red_t=reduce(t);
        if(red_s!=red_t)return false;
#ifdef DBG
        print(s,red_s);
        print(t,red_t);
        cout<<endl;
#endif
        for(int i=0;i<red_s;i++)
        {
            if(s[i]!=t[i])
                return false;
        }
        return true;
    }
};