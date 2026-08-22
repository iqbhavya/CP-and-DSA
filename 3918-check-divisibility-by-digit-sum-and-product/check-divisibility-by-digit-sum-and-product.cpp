class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sum = 0;
        int product = 1;
        for( char x : s){
            int digit = x - '0';

            sum = sum + digit;
            product = product * digit;
        }

        int div = sum + product;

        if(n % div == 0){
            return true;
        }
        return false;
    }
};