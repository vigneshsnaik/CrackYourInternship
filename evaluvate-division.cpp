class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    int n;
    double ans;
    vector<double> res;
    bool dfs(string nr, string dr, unordered_set<string>& visited) {
        for (const auto& [node, val] : adj[nr]) {
            if (visited.find(node) == visited.end()) {
                ans *= val;
                if (node == dr) {
                    res.push_back(ans);
                    return true;
                }
                visited.insert(node);
                if (dfs(node, dr, visited))
                    return true;
                ans /= val;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        n = equations.size();
        for (int i = 0; i < n; i++) {
            string nr = equations[i][0];
            string dr = equations[i][1];
            double vl = values[i];
            adj[nr].push_back({dr, vl});
            adj[dr].push_back({nr, 1.0 / vl});
        }
        for (const auto& query : queries) {
            string nr = query[0];
            string dr = query[1];
            ans = 1.0;
            unordered_set<string> visited;
            if (!dfs(nr, dr, visited))
                res.push_back(-1);
        }
        return res;
    }
};
