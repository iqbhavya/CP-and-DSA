class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.length() > s2.length()){
            return false;
        }
            

        vector<int> freqs1(26,0);
        vector<int> freqs2(26,0);

        for(int l = 0 ; l < s1.length(); l++ ){
                freqs1[s1[l] - 'a']++;
                freqs2[s2[l] - 'a']++;
        }

        bool ans = false;

        if(freqs1 == freqs2){
            ans = true; 
            
        }

        

        int w = s1.length();

        for(int i =  w; i < s2.length(); i++){
            int j = i -w;
            freqs2[s2[i] - 'a']++;
            freqs2[s2[j] - 'a']--;
            if(freqs1 == freqs2){
                ans = true; 
                break;
            }

        }


        return ans;
    }
};