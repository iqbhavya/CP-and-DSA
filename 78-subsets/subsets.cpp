class Solution {
public:

    void Sub(vector<int>& nums, int index, vector<int>& subarr,
             vector<vector<int>>& ans){

        if (index == nums.size()) {
            ans.push_back(subarr);
            return;
        }
                
        Sub(nums, index +1, subarr, ans);

        subarr.push_back(nums[index]);

        Sub(nums, index +1, subarr, ans);

        subarr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subarr;

        Sub(nums, 0, subarr,ans);

        return ans;
    }
};