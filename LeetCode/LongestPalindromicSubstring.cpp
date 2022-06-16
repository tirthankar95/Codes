class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool flag;
        int ans_len=1,ans_index=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int len=1;len<=n;len++)
        {
            flag=false;
            for(int i=0;(i+len-1)<n;i++)
            {
                if(s[i]==s[i+len-1] && (len<=2 || dp[i+1][(i+1)+(len-2)-1]))
                {
                    dp[i][i+len-1]=true;
                    if(!flag){
                        flag=true;
                        ans_index=i;
                    }
                }
            }//end of for-i.
            if(flag)ans_len=len;
        }//end of for-j.
        return s.substr(ans_index,ans_len);        
    }
};

/*
Approach 1: Longest Common Substring
Common mistake
Some people will be tempted to come up with a quick solution, which is unfortunately flawed (however can be corrected easily):
Reverse S and become S'. Find the longest common substring between S and S' which must also be the longest palindromic substring.

This seemed to work, let’s see some examples below.

For example, S = "caba", S'= "abac".
The longest common substring between S and S' is "aba", which is the answer.

Let’s try another example: S = "abacdfgdcaba", S'= "abacdgfdcaba".
The longest common substring between S and S' is "abacd". Clearly, this is not a valid palindrome.

Algorithm

We could see that the longest common substring method fails when there 
exists a reversed copy of a non-palindromic substring in some other part of SS. 
To rectify this, each time we find a longest common substring candidate, we check 
if the substring’s indices are the same as the reversed substring’s original 
indices. If it is, then we attempt to update the longest palindrome found so far; 
if not, we skip this and find the next candidate.

https://www.geeksforgeeks.org/longest-common-substring-dp-29/
Can be done in O(n)
*/

/*
*/