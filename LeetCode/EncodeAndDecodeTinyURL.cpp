#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
#define MX_NO (10)
#define MX_ALPHA (26)
#define MX_SYMBOL (MX_NO+2*MX_ALPHA)

class Solution {
	int gCount;
	unordered_map<int, string> mapped;
	char symbolMap[MX_SYMBOL];
	unordered_map<char, int> symbolMapR;
	string convert_(int no) {
		string res = "";
		if (no == 0)return res+symbolMap[0];
		while (no) {
			res = symbolMap[no % MX_SYMBOL]+res;
			no /= MX_SYMBOL;
		}
		return res;
	}
	string convertR_(string shortUrl) {
		int n = shortUrl.length();
		int hashVal = 0;
		int pow = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			hashVal += symbolMapR[shortUrl[i]] * pow;
			pow = pow * MX_SYMBOL;
		}
		return mapped[hashVal];
	}
public:
	Solution() {
		gCount = 0;
		mapped.clear();
		int i=0;
		for (; i < MX_NO; i++) {
			symbolMap[i] = (char)('0' + i);
			symbolMapR[char('0' + i)] = i;
		}
		for (int j = 0; i < MX_NO + MX_ALPHA; j++,i++) {
			symbolMap[i] = (char)('A' + j);
			symbolMapR[(char)('A' + j)] = i;
		}
		for (int j=0; i < MX_SYMBOL; j++,i++) {
			symbolMap[i] = (char)('a' + j);
			symbolMapR[(char)('a' + j)] = i;
		}
	}
	string encode(string longUrl) {
		string res = convert_(gCount);
		mapped[gCount++] = longUrl;
		return res;
	}
	string decode(string shortUrl) {
		return convertR_(shortUrl);
	}
};