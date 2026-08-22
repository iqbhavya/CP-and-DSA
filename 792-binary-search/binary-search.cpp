class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int st = 0;
        int end = n;

        while(st < end){
            int mid = st + (end - st)/2;

            if(target == nums[mid]){
                return mid;
            }

            if(nums[mid] >= target){
                end = mid;
            }else{
                st = mid+1;
            }
        }

        return -1;
    }
};