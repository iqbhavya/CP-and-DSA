class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int st = nums[0];
        int end = nums[nums.size()-1];

        vector<int> miss;
        int j = 0;
        for(int i = st; i<= end ; i++){
            
            if(nums[j] != i){
                miss.push_back(i);
            }else if(nums[j] == i){
                j++;
            }
            
        }

        return miss;
    }
};