class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(s.length() + 1, vector<bool>(p.length() + 1));
        
        // initialize first column and first row
        match[0][0] = true;
        for (int i = 1; i < p.length() + 1; i++) {
            match[0][i] = p[i - 1] == '*' ? match[0][i - 2] : false;
        }
        
        // build up a (n + 1) by (, + 1) board using dynamic programming
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < p.length(); j++) {
                if (s[i] == p[j] || p[j] == '.') {
                    match[i + 1][j + 1] =  match[i][j];
                } else if (p[j] == '*') {
                    match[i + 1][j + 1] = p[j - 1] == '.' || p[j - 1] == s[i] ? match[i + 1][j - 1] | match[i][j + 1]: match[i + 1][j - 1];
                } else  {
                    match[i + 1][j + 1] = false;
                }
            }
        }
        return match[s.length()][p.length()];
    }
};