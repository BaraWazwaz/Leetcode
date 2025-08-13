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

class Solution {
    map<Node*, Node*> bijector;
    void dfsCollect(Node* src) {
        bijector[src] = nullptr;
        for (auto& nbr : src->neighbors)
            if (!bijector.count(nbr))
                dfsCollect(nbr);
    }
    void buildParallel(Node* constructing, Node* existing) {
        bijector[existing] = constructing;
        for (auto& nbr : existing->neighbors) {
            if (bijector[nbr] == nullptr)
                buildParallel(bijector[nbr] = new Node(nbr->val), nbr);
            constructing->neighbors.push_back(bijector[nbr]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        bijector.clear();
        dfsCollect(node);
        Node* ans = new Node(node->val);
        buildParallel(ans, node);
        return ans;
    }
};