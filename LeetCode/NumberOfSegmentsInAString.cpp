class Solution {
public:
    int countSegments(string s) {
        stringstream newString(s);
        int cnt=0;
        string tmp;
        while(newString >> tmp)cnt++;
        return cnt;
    }
};