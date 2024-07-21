class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        vector<int> cnt(26, 0);
        for (char task : tasks)
            cnt[task - 'A']++;
        int maxCount = 0;
        int sameMaxCount = 0;
        for (int count : cnt) {
            if (count > maxCount) {
                maxCount = count;
                sameMaxCount = 1;
            } else if (count == maxCount) {
                sameMaxCount++;
            }
        }
        return max((n + 1) * (maxCount - 1) + sameMaxCount, (int)tasks.size());
    }
};
