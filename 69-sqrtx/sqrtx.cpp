class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        int ans = 0;

        for (int i = 0; i <= x / 2 + 1; i++) {
            long long val = 1LL * i * i;

            if (val <= x)
                ans = i;
            else
                break;
        }

        return ans;
    }
};