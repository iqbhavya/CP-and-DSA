#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        
        for(int i = 0; i < pattern.size(); i++){
            char a = pattern[i];
            
            string b = words[i];

            if(mp1.count(a) && mp1[a] != b){
                return false;
            }
            if(mp2[b] && mp2[b] != a){
                return false;
            }

            mp1[a] = b;
            mp2[b] = a;

            
        }

        return true;
    }
};