class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  

public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int x : nums){
            if(minHeap.size()< k){
                minHeap.push(x);
            } else if(x > minHeap.top()){
                minHeap.push(x);
                if(minHeap.size() > k){
                    minHeap.pop();
                }
            }
        } 
    }
    
    int add(int val) {
        if(minHeap.size() < k){
            minHeap.push(val);
        }else if(val > minHeap.top()){
            minHeap.push(val);
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */