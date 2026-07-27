class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int st = 0;
        int end = n-1;

        while(st < end){
            int mid = st + (end - st)/2;

            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
                return mid;
            }

            if(arr[mid] < arr[mid+1]){
                st = mid;
            }else if(arr[mid] > arr[mid+1]){
                end = mid;
            }else{
                mid = mid+1;
            }
        }

        return 0;
    }
};