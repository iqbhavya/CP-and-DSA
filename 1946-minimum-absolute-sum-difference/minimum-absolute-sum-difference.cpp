class Solution {
public:
    const long long MOD = 1e9 + 7;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        int total = 0;

        vector<int> dif(n);

        for(int i = 0; i< n; i++){
            dif[i] = abs(nums1[i] - nums2[i]);
            total = (total + dif[i])%MOD;
        }

        vector<int> arr(n);

        sort(nums1.begin(), nums1.end());

        for(int i = 0; i < n; i++){
            int j = lower_bound(nums1.begin(), nums1.end() , nums2[i]) - nums1.begin();

            if(j != 0 && j != n){
                arr[i] = min(abs(nums1[j] - nums2[i]) ,abs(nums1[j-1] - nums2[i]));
            }else if(j == 0){
                arr[i] = abs(nums1[j] - nums2[i]);
            }else if(j == n){
                arr[i] = abs(nums1[j-1] - nums2[i]);
            }
        }

        int bestsave =0;
        for(int i= 0; i < n; i++){
            bestsave = max(bestsave, dif[i] - arr[i]);
        }

        return (total - bestsave + MOD) % MOD;
    }
};