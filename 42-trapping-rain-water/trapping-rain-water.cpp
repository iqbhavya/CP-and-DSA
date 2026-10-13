class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int rightmax[20000];
        rightmax[n-1]= INT_MIN;
        int leftmax[20000];
        leftmax[0] = INT_MIN;

        for(int i = 1; i < n ; i++ ){
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }

        for(int i = n-2; i >= 0 ; i--){
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }

        int trapped_water = 0;

        for(int k = 1; k < n-1; k++){
            int minheight = min(rightmax[k], leftmax[k]);

            if( minheight - height[k] > 0){
                trapped_water +=  minheight - height[k];
            }

            
        }

        return trapped_water;
    }
};