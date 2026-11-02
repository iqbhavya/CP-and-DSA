class Solution {
public:

    void swap(vector<int>& nums, int start , int end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }

    void reverse(vector<int>& nums, int start , int end){
        while(start < end){
            swap(nums , start, end);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i = n-2 ; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index != -1){
            for(int i = n-1; i > index; i--){
                if(nums[i] > nums[index]){
                    swap(nums, i , index);
                    break;
                }
            }
        }

        reverse(nums, index+1, n-1);
    }
};