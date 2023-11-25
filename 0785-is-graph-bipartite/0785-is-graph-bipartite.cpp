class Solution {
private:
    bool dfscheck(int node, vector<int> &color, vector<vector<int>>& graph) {
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                color[it] = !color[node];
                if (!dfscheck(it, color, graph)) {
                    return false;
                }
            }
            else if (color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!dfscheck(i, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};

