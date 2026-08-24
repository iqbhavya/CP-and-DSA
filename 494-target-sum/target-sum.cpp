class Solution {
public:
    void values(vector<int>& nums,int target , int sum, int index, int& ans){

        if(index == nums.size()){
            if(sum == target){
                ans = ans + 1;
            }
            return;
        }

        values(nums, target , sum + nums[index] , index + 1, ans);
        values(nums, target , sum - nums[index], index + 1 , ans);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        values(nums, target , 0 , 0 ,ans );

        return ans;
    }   
};