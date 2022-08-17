class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) { return s.length(); }
        int len = 0;
        int start = 0;
        for (int i = 1; i < s.length(); i++) {
            int j = i - 1;
            while (j >= start) {
                if (s[j] == s[i]) {
                    if (i - j > len) {
                        len = i - j; 
                    }
                    start = j + 1;
                    break;
                }
                j--;
            }
            if (j < start && i - j > len) {
                len = i - j;
            }
        }
        
        return len;
    }
};