class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int index = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                index = i;
            }
        }

        if(index == -1){
            for(int i = 0; i < n; i++){
                if(target < nums[i]){
                    return i;
                }
            }
            return n;
        }

        return index;


    }
};