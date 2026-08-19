class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        int minabs = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 1; i< arr.size(); i++){
            minabs = min(minabs, arr[i] - arr[i-1]);
        }

        for(int i = 1; i< arr.size(); i++){
            int dif = arr[i] - arr[i-1];
            if(dif == minabs){
                ans.push_back({arr[i-1] , arr[i]});
            }
        }

        return ans;
    }
};