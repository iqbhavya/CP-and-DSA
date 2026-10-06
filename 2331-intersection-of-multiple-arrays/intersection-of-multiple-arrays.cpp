class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        

        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){

                if( mp.count(nums[i][j]) > 0){
                    mp[nums[i][j]]++;
                }else {
                    mp[nums[i][j]] = 1;
                }
                
            }
        }

        for( pair<int,int> x : mp){
            if(x.second >= nums.size() ){
                ans.push_back(x.first);
            }
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};