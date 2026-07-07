class Solution {
public:
    bool isValid(string s) {
        stack<char> para;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                para.push(c);
            }else {
                if(para.empty()) return false;

                if ((c == ')' && para.top() != '(') ||
                    (c == ']' && para.top() != '[') ||
                    (c == '}' && para.top() != '{')){

                        return false;
                    }
                para.pop();    
            }
            
        }

        if(para.empty()){
            return true;
        }
        return false;
        
    }
};