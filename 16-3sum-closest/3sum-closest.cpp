class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        

        for(int i = 0; i < n; i++){

            int left = i+1;
            int right = n-1;

            while(left < right){

                int current_sum = nums[i] + nums[left] + nums[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if(abs(target - closestSum) > abs(target - current_sum)){
                    closestSum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }

            }

            
            
        }

        return closestSum;
    }
};