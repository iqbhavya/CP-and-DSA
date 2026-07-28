class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int f = 0;
        s = nums[s];
        f = nums[nums[f]];
        while (s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }

        int s2 = 0;
        while (s != s2) {
            s = nums[s];
            s2 = nums[s2];
            if (s == s2) {
                return s;
            }
        }

        return s2;
    }
};