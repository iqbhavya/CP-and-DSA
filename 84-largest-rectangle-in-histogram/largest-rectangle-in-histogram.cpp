class Solution {
public:

    vector<int> leftSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> lsr(n);
        stack<int> s;

        lsr[0] = -1;
        s.push(0);
        for(int i = 0; i < n; i++){
            int curr = nums[i];
            while(!s.empty() &&  curr <= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                lsr[i] = -1;
            }else{
                lsr[i] = s.top();
            }
            
            s.push(i);

        }

        return lsr;
        
    }

    vector<int> rightSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> rsr(n);
        stack<int> s;
        
        rsr[n-1] = n;
        s.push(n-1);
        for(int i = n-1; i >= 0 ; i--){
            int curr = nums[i];
            while(!s.empty() &&  curr <= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                rsr[i] = n;
            }else{
                rsr[i] = s.top();
            }
            
            s.push(i);

        }

        return rsr;
        
    }

    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;

        vector<int> lsr = leftSmaller(heights);
        vector<int> rsr = rightSmaller(heights);

        for(int i= 0 ; i < heights.size() ; i++){
            int currArea = heights[i] * (rsr[i] - lsr[i] -1);
            ans = max(ans , currArea);
        }

        return ans;
    }
};