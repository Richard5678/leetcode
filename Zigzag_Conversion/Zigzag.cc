class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string str = "";
        int cycleLength = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += cycleLength) {
                str += s[j];
                int len = 2 * (numRows - 1 - i);
                if (len % cycleLength != 0 && j + len < s.length()) {
                    str += s[j + len];
                }
            }
        }
        
        return str;
    }
};