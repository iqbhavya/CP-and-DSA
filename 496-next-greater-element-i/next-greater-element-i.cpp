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

        for(int i = 0; i < nums1.size() ; i++){
            for(int j = 0; j < nums2.size() ; j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(next[j]);
                }
            }
        }
        return ans;
        
    }
};