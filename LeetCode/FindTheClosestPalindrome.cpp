class Solution {
public:
    
    string solve(string s, int n) {
        string temp = s.substr(0, n);
        if(temp == "0")
            temp = "";
        if(temp.length() != n)
             temp.push_back('9');
        reverse(temp.begin(), temp.end());
        return s + temp;
    }
    
    
    string nearestPalindromic(string n) {
        long long int len = n.length();
        long long int N = stol(n);
        long long int res = 0;
        for(int i = 0; i < (len + 1) /2; i++) {
            
            res = res * 10 + n[i] - '0';
        }
        
        string n1 = to_string(res); 
        string n2 = to_string(res + 1);
        
        string n3 = to_string(res - 1); 
        int final_res = INT_MAX;
        
        long long int N1 = stol(solve(n1, len / 2)); 
        long long int N2 = stol(solve(n2, len / 2));    
        long long int N3 = stol(solve(n3, len / 2));

        string ans = "";
        if(N != N1 and final_res > abs(N - N1)) {
            
            final_res =  abs(N - N1);
            ans = to_string(N1);
            
        }
        if(N != N2 and final_res > abs(N - N2)) {
            
            final_res =  abs(N - N2);
            ans = to_string(N2);
            
        }
        if(N != N3 and final_res >= abs(N - N3)) {
            
            final_res =  abs(N - N3);
            ans = to_string(N3);
            
        }
        return ans;
    }
};