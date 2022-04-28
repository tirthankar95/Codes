typedef pair<int, int> ii;
typedef pair<int, ii> iii;

class Solution {
    class UF {
        int n;
        vector<int> parent;
        vector<int> sz;
    public:
        UF(int n) {
            this->n = n;
            parent.resize(n);
            for (int i = 0; i < n; i++)parent[i] = i;
            sz.resize(n, 1);
        }
        void union_(int a, int b) {
            int rootA = root_(a);
            int rootB = root_(b);
            if (sz[rootA] >= sz[rootB]) {
                sz[rootA] += sz[rootB];
                parent[rootB] = parent[rootA];
            }
            else {
                sz[rootB] += sz[rootA];
                parent[rootA] = parent[rootB];
            }
        }
        int root_(int a) {
            while (a != parent[a]) {
                parent[a] = parent[parent[a]];
                a=parent[a];
            }
            return a;
        }
    };
    inline int mDist(vector<int>& d0, vector<int>& d1) {
        return abs(d0[0] - d1[0]) + abs(d0[1] - d1[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int edges = (n * (n - 1)) / 2;
        vector<iii> kruskal(edges);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                kruskal[count++] = iii(mDist(points[i], points[j]), ii(i, j));
        }//end of i.
        sort(kruskal.begin(), kruskal.end());
        int res = 0;
        count = 0;//reuse.
        UF obj(n);
        for (int i = 0; i < edges; i++) {
            if (obj.root_(kruskal[i].second.first) != obj.root_(kruskal[i].second.second))
            {
                obj.union_(kruskal[i].second.first, kruskal[i].second.second);
                res += kruskal[i].first;
                count++;
            }
            if (count == n - 1)
                break;
        }
        return res;
    }
};