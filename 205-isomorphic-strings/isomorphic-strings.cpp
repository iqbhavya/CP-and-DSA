class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char,char> mp2;

        if(s.size() != t.size()){
            return false;
        }

        for(int i = 0; i < s.length(); i++){
            char sc = s[i];
            char tc = t[i];

           
            if (mp1.count(sc) && mp1[sc] != tc) return false;
            if (mp2.count(tc) && mp2[tc] != sc) return false;

            mp1[sc] = tc;
            mp2[tc] = sc;
        }
        return true;
    }
};