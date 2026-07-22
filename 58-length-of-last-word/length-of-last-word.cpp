

class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = 0;
        int l = s.length() - 1;

        
        while (l >= 0 && s[l] == ' '){
            l--;
        }

        for(int i = 0; i <= l; i++){
            if(s[i] != ' '){
                n++;
            }else {
                n = 0;
            }
        }

        return n;
    }
};