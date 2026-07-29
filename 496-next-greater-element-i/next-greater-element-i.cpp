class Solution {
public:

    vector<int> nextgreater(vector<int>& nums){
        vector<int> ans(nums.size());

        stack<int> st;

        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]  ){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next = nextgreater(nums2);
        vector<int> ans;

        unordered_map<int, int> mp;

        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = next[i];
        }
        for(int x : nums1){
            ans.push_back(mp[x]);
        }

        return ans;
        
    }
};