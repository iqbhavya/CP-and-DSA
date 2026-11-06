class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for(int i = 0 ; i < nums.size(); i++){
            
                int j = 0;
                while(j < nums.size()-1){
                    if(nums[j] == 0){
                        swap(nums[j], nums[j+1]);
                    }
                    j++;
                }
            
            
        }
        
    }
};