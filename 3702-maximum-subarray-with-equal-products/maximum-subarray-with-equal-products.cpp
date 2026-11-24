
class Solution {
public:
    int maxLength(std::vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;

       
        const long long MAX_LIMIT = 25200;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                prod *= nums[j];

                
                if (prod > MAX_LIMIT) {
                    break;
                }

                g = gcd(g, static_cast<long long>(nums[j]));
                l = lcm(l, static_cast<long long>(nums[j]));

                if (prod == l * g) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};