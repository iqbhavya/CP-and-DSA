class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) return result;

        
        using ele = tuple<int,int,int>;
        priority_queue<ele, vector<ele>, greater<ele>> pq;
        
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < min(n1, k); ++i) {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }
        
        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            result.push_back({nums1[i], nums2[j]});

            
            if (j + 1 < n2) {
                pq.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
    
};