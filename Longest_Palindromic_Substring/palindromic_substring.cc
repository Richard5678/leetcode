class Solution {
public:
    string longestOddPalidrome(string &s) {
        int maxLen = 1;
        int maxLeft = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
                    left--;
                    right++;
                } else {
                    if (right - left + 1 > maxLen) {
                        maxLeft = left + 1;
                        maxLen = right - left - 1;
                    }
                    break;
                }
            }
            if (left < 0 || right >= s.length() && right - left - 1 > maxLen) {
                maxLeft = left + 1;
                maxLen = right - left - 1;
            }
        }
        
        return s.substr(maxLeft, maxLen);
    }
    
    string longestEvenPalidrome(string &s) {
        int maxLen = 1;
        int maxLeft = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i;
            int right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
                    left--;
                    right++;
                } else {
                    if (right - left - 1 > maxLen) {
                        maxLeft = left + 1;
                        maxLen = right - left - 1;
                    }
                    break;
                }
                
            }
            
            if (left < 0 || right >= s.length() && right - left - 1 > maxLen) {
                maxLeft = left + 1;
                maxLen = right - left - 1;
            }
        }
        
        return s.substr(maxLeft, maxLen);
    }
    
    string longestPalindrome(string s) {
        string oddStr = longestOddPalidrome(s);
        string evenStr = longestEvenPalidrome(s);
        return (oddStr.length() < evenStr.length())  ? evenStr : oddStr;
    }
};