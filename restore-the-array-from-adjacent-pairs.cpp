class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> neighbours;
        for (auto& pair : adjacentPairs) {
            neighbours[pair[0]].push_back(pair[1]);
            neighbours[pair[1]].push_back(pair[0]);
        }
        vector<int> res;
        for (auto& e : neighbours) {
            if (e.second.size() == 1) {
                res.push_back(e.first);
                res.push_back(e.second[0]);
                break;
            }
        }
        while (res.size() <= adjacentPairs.size()) {
            res.push_back(neighbours[res.back()][0] != *(res.rbegin() + 1)
                              ? neighbours[res.back()][0]
                              : neighbours[res.back()][1]);
        }
        return res;
    }
};
