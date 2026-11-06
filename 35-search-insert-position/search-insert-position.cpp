class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int st = 0; 
        int end = nums.size();
       

        while(st < end){
            int mid = st + (end - st)/2;

            if(nums[mid] >= target){
                end = mid;
            }else {
                st = mid+1;
            }
        }

        

        return st;


    }
};