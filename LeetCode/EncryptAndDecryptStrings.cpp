//Encrypt and Decrypt Strings
/*
	I was traversing the Trie form begining after adding each character. This gave TLE.
	Instead traversing Trie from where it has already been traversed give successful result.
*/
class node {
public:
	bool isLeaf;
	node* children[26];
	node() {
		isLeaf = false;
		for (int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};
const int mxSize = 1e6 + 1;
node* res_copy[mxSize];
node* res_[mxSize];

class Trie {
public:
	node* parent;
	Trie() {
		parent = new node;
	}
	void insert(string s) {
		node* iter = parent;
		for (int i = 0; i < s.length(); i++)
		{
			if (iter->children[(int)(s[i] - 'a')] == NULL)
				iter->children[(int)(s[i] - 'a')] = new node;
			iter = iter->children[(int)(s[i] - 'a')];
		}
		iter->isLeaf = true;
	}//end of insert.
};

class Encrypter {
	Trie* obj;
	unordered_map<char, string> hMap;
	unordered_map<int, vector<char>> rhMap;
	int getHash(char s0, char s1) { return (s0 * 255 + s1); }
public:
	Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
		int n = keys.size();
		for (int i = 0; i < n; i++)
		{
			hMap[keys[i]] = values[i];
			rhMap[getHash(values[i][0], values[i][1])].push_back(keys[i]);
		}
		obj = new Trie;
		int m = dictionary.size();// Put this in a trie.
		for (int i = 0; i < m; i++)
			obj->insert(dictionary[i]);
	}
	string encrypt(string word1) {
		string res = "";
		int n = word1.length();
		for (int i = 0; i < n; i++)
			res += hMap[word1[i]];
		return res;
	}
	int decrypt(string word2) {
		int n = word2.length(), temp_rs;
		int rs = 1; res_[0] = obj->parent;
		string temp;
		vector<char> possible;
		for (int i = 0; i < n; i += 2) {
			possible = rhMap[getHash(word2[i], word2[i + 1])];
			for (int i = 0; i < rs; i++)res_copy[i] = res_[i];
			temp_rs = 0;
			for (int j = 0; j < possible.size(); j++) {
				for (int k = 0; k < rs; k++) {
					if (res_copy[k]->children[(int)(possible[j] - 'a')])
						res_[temp_rs++] = res_copy[k]->children[(int)(possible[j] - 'a')];
				}
			}
			rs = temp_rs;
		}//end of outer-for.
		int count = 0;
		for (int i = 0; i < rs; i++)
			if (res_[i]->isLeaf)
				count++;
		return count;
		}
	};
/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */