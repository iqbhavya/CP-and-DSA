class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<int> window;
        int minSum = INT_MAX;

        for (int i = l; i <= n; ++i) {
            
            window.insert(prefix[i - l]);

  
            auto it = window.lower_bound(prefix[i]);
            if (it != window.begin()) {
                --it;
                minSum = min(minSum, prefix[i] - *it);
            }

            if (i >= r) {
                window.erase(window.find(prefix[i - r]));
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};