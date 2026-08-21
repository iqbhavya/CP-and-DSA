class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int size = tasks.size();
        for(int i =0 ; i< size; i++){
            freq[ tasks[i] - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];
        int space = maxFreq-1;
        int idle = n*space;

        int count = 0;

        for(int i = 24; i>= 0; i--){
            if(freq[i] > 0){
                idle = idle - min(freq[i], space);
                freq[i]--;
            }
        }

        if(idle > 0){
            return tasks.size() + idle;
        }

        return tasks.size();
    }
};