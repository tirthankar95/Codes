//Check the explanation of the Solution
//Centroid problem with proof that a tree can have at max 2 centroids.

typedef vector<int> vi;
const int mxSize=2e4+1;
unordered_map<int,int> hashMap;
vi adj[mxSize];
int ht[mxSize];

class Solution {
    int N;
    int hash(int x0,int x1){
        return x0*N+x1;
    }
    int dfs(int src,int parent){
        int mx=-1;
        for(int i=0;i<adj[src].size();i++)
        {
            if(parent!=adj[src][i])
            {
                int element=hash(src,adj[src][i]);
                if(hashMap.find(element)==hashMap.end())
                    hashMap[element]=dfs(adj[src][i],src);
                mx=max(mx,hashMap[element]);
            }
        }
        hashMap[hash(parent,src)]=1+mx;
        return 1+mx;
    }
public:
    vi findMinHeightTrees(int n, vector<vi>& edges) {
        N=n;
        int m=edges.size();
        hashMap.clear();
        for(int i=0;i<n;i++)
            adj[i].clear(),ht[i]=0;
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int mi_h=n;
        for(int i=0;i<n;i++)
        {
            ht[i]=dfs(i,-1);
            mi_h=min(mi_h,ht[i]);
        }
        vi sol;
        for(int i=0;i<n;i++)
            if(mi_h==ht[i])sol.push_back(i);
        return sol;
    }
};

/* Optimal Python Solution

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:

        # base cases
        if n <= 2:
            return [i for i in range(n)]

        # Build the graph with the adjacency list
        neighbors = [set() for i in range(n)]
        for start, end in edges:
            neighbors[start].add(end)
            neighbors[end].add(start)

        # Initialize the first layer of leaves
        leaves = []
        for i in range(n):
            if len(neighbors[i]) == 1:
                leaves.append(i)

        # Trim the leaves until reaching the centroids
        remaining_nodes = n
        while remaining_nodes > 2:
            remaining_nodes -= len(leaves)
            new_leaves = []
            # remove the current leaves along with the edges
            while leaves:
                leaf = leaves.pop()
                # the only neighbor left for the leaf node
                neighbor = neighbors[leaf].pop()
                # remove the only edge left
                neighbors[neighbor].remove(leaf)
                if len(neighbors[neighbor]) == 1:
                    new_leaves.append(neighbor)

            # prepare for the next round
            leaves = new_leaves

        # The remaining nodes are the centroids of the graph
        return leaves

*/