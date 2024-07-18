class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto j = nums.begin() + 1;
        for (auto i = nums.begin() + 1; i != nums.end(); i++) {
            if (*i != *(i - 1)) {
                *j = *i;
                j++;
            }
        }
        return j - nums.begin();
    }
};
