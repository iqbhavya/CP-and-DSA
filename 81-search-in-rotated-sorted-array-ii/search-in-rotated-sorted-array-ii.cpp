class Solution {
    public:
        int search(vector<int>& nums, int target){                                                                
        

        if(nums.empty()){
            return false;
        }
        
        int st = 0 ; 
        int end = nums.size()-1;

        while(st <= end){

            int mid = end + (st-end)/2;

            if(target == nums[mid]){
                return true;
            }

            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue;
            }

            if(nums[mid]>=nums[st]){
                if(target < nums[mid] && target >= nums[st]){
                    end = mid-1;
                } else {
                    st = mid + 1;
                }

            }
            else {
                if(target > nums[mid] && target <= nums[end]){
                    st = mid+1;
                }else {
                    end = mid-1;
                }
            }
        }
        return false;
        
        
    };
};