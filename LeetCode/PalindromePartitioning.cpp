class Solution {
    int N;
    vector<vector<string>> sol;
    bool isPalin(string s,int lb,int ub){
        while(lb<ub){
            if(s[lb++]!=s[ub--])
                return false;
        }
        return true;
    }
    void fn(int lb,string s,vector<string>& sArr){
        if(lb>=N){
            sol.push_back(sArr);
            return;
        }
        int ub=lb;
        for(;ub<s.length();ub++){
            if(isPalin(s,lb,ub)){
                sArr.push_back(s.substr(lb,ub-lb+1));
                fn(ub+1,s,sArr);
                sArr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        N=s.length();
        sol.clear();
        vector<string> tmp;
        fn(0,s,tmp);
        return sol;
    }
};
/*
Slightly faster because there is no need to check whether the substring is palindrome here.
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
*/