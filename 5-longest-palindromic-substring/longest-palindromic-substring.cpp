class Solution {
public:
    int expand(string& s , int right , int left){
        while(right < s.length() && left >= 0 && s[right] == s[left]){
            right++;
            left--;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if ( s.empty()) return " ";

        int start = 0;
        int maxLength = 0;
        int n = s.length();

        for(int i = 0; i < s.length(); i++){
            
            int len1 = expand(s, i , i+1);

            int len2 = expand(s, i , i);

            int len = max(len1,len2);

            if ( len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }


        return s.substr(start, maxLength);
    }
};