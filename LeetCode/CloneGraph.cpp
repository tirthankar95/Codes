/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
const int mx=101;
namespace local{
    Node* map[mx];
}

class Solution {
    Node* dfsC(Node* node){
        if(!node)return NULL;
        Node* nodeC=new Node(node->val);
        local::map[node->val]=nodeC;
        int n=node->neighbors.size();
        for(int i=0;i<n;i++){
            if(!local::map[node->neighbors[i]->val])
                nodeC->neighbors.push_back(dfsC(node->neighbors[i]));
            else 
                nodeC->neighbors.push_back(local::map[node->neighbors[i]->val]);
                
        }
        return nodeC;
    }
public:
    Node* cloneGraph(Node* node) {
        memset(local::map,NULL,sizeof(local::map));
        return dfsC(node);
    }
};