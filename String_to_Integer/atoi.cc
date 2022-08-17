class Solution {
public:
    
    int myAtoi(string s) {
        int limit = s.length();
        int answer = 0;
        
        const int int_min = INT_MIN / 10;
        const int int_max = INT_MAX / 10;
        int length = 0;
        bool neg = false;
        bool digitReached = false;
        bool signReached = false;
        for (int i = 0; i < limit; i++) {
            if (s[i] != '-' && s[i] != '+' && s[i] != ' ' && ('0' > s[i] || s[i] > '9')) {
                if (neg) {
                    return -answer;
                } else {
                    return answer;
                }
            }
            
            if ((signReached || digitReached) && ('0' > s[i] || s[i] > '9')) {
                break;
            }
            
            if (s[i] == '-' || s[i] == '+') {
                signReached = true;
            }
            if (s[i] == '-' && !digitReached) {
                neg = true;
            }
            if ('0' <= s[i] && s[i] <= '9') {
                digitReached = true;
            }
    
            
            if (digitReached) {
                int digit = s[i] - '0';
                if (neg && length >= 9 && (-answer < int_min || (-answer == int_min && digit >= 8))) {
                    return INT_MIN;
                } 
                if (!neg && length >= 9 && (answer > int_max || (answer == int_max && digit >= 7))) {
                    return INT_MAX;
                }
                
                length++;
                answer = answer * 10 + digit;
            }
        }
        
        if (neg) {
            return -answer;
        } else {
            return answer;
        }
    }
};