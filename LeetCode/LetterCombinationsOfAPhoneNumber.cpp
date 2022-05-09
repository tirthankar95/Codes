//#define DBG
class Solution {
    vector<string> sol;
    int n;
    void bt(vector<string>& map_,string& digits,string temp,int i){
        if(i>=n)
        {
            sol.push_back(temp);
            return;
        }
        for(int j=0;j<map_[(int)(digits[i]-'0')].length();j++)
            bt(map_,digits,temp+map_[(int)(digits[i]-'0')][j],i+1);
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map_(10);
        int m;n=digits.length();
        char start_='a';
        for(int i=2;i<=9;i++){
            m=(i==7 || i==9)?4:3;
            for(int j=0;j<m;j++)
            map_[i]+=(char)(start_+j);
            start_+=m;
        }
#ifdef DBG
        for(int i=2;i<=9;i++)
            cout<<map_[i]<<" ";
        cout<<endl;
#endif
        sol.clear();
        if(n==0)return sol;
        bt(map_,digits,"",0);
        return sol;
    }
};