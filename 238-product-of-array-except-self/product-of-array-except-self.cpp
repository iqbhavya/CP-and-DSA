class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProd;
        vector<int> sufixProd(nums.size());

        vector<int> ans;

        int prod = 1;

        for(int i = 0; i< nums.size(); i++){
            prod = prod * nums[i];

            prefixProd.push_back(prod);
        }

        prod = 1;

        for(int i = nums.size()-1; i >= 0; i--){
            prod = prod * nums[i];

            sufixProd[i] = prod;
        }

        for(int i = 0; i < nums.size(); i++){

            if(i == 0){
                ans.push_back(sufixProd[1]);
                continue;
            }if(i == nums.size()-1){
                ans.push_back(prefixProd[i-1]);
                continue;
            }

            
            long long a = prefixProd[i-1] * sufixProd[i+1];
            ans.push_back(a);
            
            
        }

        return ans;

    }
};