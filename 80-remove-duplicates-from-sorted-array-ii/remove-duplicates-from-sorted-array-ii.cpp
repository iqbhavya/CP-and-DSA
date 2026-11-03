class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        

        if(nums.size()<= 2){
            return nums.size();
        }
        int j = 2;
        
        for(int i = 2; i <= nums.size()-1; i=i+1){
            
            if(nums[i] != nums[j-2]){
                
                nums[j] = nums[i];
                j++;
                
            }
            
        }
        return j;
    }
};