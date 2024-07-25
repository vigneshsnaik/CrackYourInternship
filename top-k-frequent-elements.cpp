class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for (auto& [num, count] : counts) {
            maxHeap.push({count,num});
        }
        vector<int> res;
        while(k--) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
