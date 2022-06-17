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
pproach 4: Expand Around Center
In fact, we could solve it in O(n^2) time using only constant space.
We observe that a palindrome mirrors around its center. Therefore, 
a palindrome can be expanded from its center, and there are only 2n - 1 such centers.

You might be asking why there are 2n - 12n−1 but not nn centers? 
The reason is the center of a palindrome can be in between two letters. 
Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.

public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}
*/

/*
Manacher’s Algorithm – Linear Time Longest Palindromic Substring
const int mxSize=3e3+1;
int L[mxSize];

string findLongestPalindromicString(string text) 
{ 
    int N = text.length(); 
    if(N<=1)return text;
    N = 2*N + 1; 
    memset(L,0,N*sizeof(int));
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition 
    int R = 2; //centerRightPosition 
    int i = 0;  
    int iMirror; //currentLeftPosition 
    int expand = -1; 
    int diff = -1; 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    for (i = 2; i < N; i++) 
    { 
        iMirror = 2*C-i; 
        expand = 0; 
        diff = R - i; 
        if(diff >= 0) 
        { 
            if(L[iMirror] < diff) // Case 1 
                L[i] = L[iMirror]; 
            else if(L[iMirror] == diff && R == N-1) // Case 2 
                L[i] = L[iMirror]; 
            else if(L[iMirror] == diff && R < N-1) // Case 3 
            { 
                    L[i] = L[iMirror]; 
                    expand = 1; // expansion required 

            } 
            else if(L[iMirror] > diff) // Case 4 
            { 
                L[i] = diff; 
                expand = 0; // expansion required 
            } 
        } 
        else
        { 
            L[i] = 0; 
            expand = 1; // expansion required 

        } 
        if (expand == 1) 
        { 
            while (((i + L[i]) < N && (i - L[i]) > 0) && ( ((i + L[i] + 1) % 2 == 0) || 
                (text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] ))) 
            { 
                L[i]++; 
            }
        } 
        if(L[i] > maxLPSLength)
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
        if (i + L[i] > R) 
        { 
            C = i; 
            R = i + L[i]; 
        } 
    } 
    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    return text.substr(start,maxLPSLength);
} 
class Solution {
public:
    string longestPalindrome(string s) {
        return findLongestPalindromicString(s);
    }
};
*/