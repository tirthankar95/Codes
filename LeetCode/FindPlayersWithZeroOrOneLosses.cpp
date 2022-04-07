// Find Players With Zero or One Losses.
class Solution1{
	typedef vector<int> vi;
	typedef vector<vi> vvi;
	class graph {
		int n;
		unordered_map<int, int> count;
	public:
		graph(int n) {
			this->n = n;
			count.clear();
		}
		void addEdge(int u,int v) {
			count[u]++;
			if (count.find(v) == count.end())
				count[v] = 0;
		}
		vvi getSolution() {
			vi s0, s1;
			for (unordered_map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
				if (it->second == 0)
					s0.push_back(it->first);
				if (it->second == 1)
					s1.push_back(it->first);
			}
			vvi sol;
			sort(s0.begin(), s0.end()); sort(s1.begin(), s1.end());
			sol.push_back(s0); sol.push_back(s1);
			return sol;
		}
	};
public:
	vvi findWinners(vvi& matches) {
		int n = matches.size();
		graph obj(n);
		for (int i = 0; i < n; i++)
			obj.addEdge(matches[i][1],matches[i][0]);
		return obj.getSolution();
	}
};