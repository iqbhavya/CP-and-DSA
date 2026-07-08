class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length()){
            return false;
        }
            

        vector<int> freqs1(26,0);

        for(int l = 0 ; l < s1.length(); l++ ){
                freqs1[s1[l] - 'a']++;
        }

        bool ans = false;

        int w = s1.length();

        for(int i =  w; i <= s2.length(); i++){
            int j = i -w;
            
            vector<int> freqs2(26,0);

            
            for(int l = j ; l < i; l++ ){
                freqs2[s2[l] - 'a']++;
            }

            if(freqs1 == freqs2){
                ans = true; 
                break;
            }
            
        }


        return ans;
    }
};