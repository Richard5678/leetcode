class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxL = 0, i = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == '(')
            {
                left++;   
            }
            else
            {
                right++;
            }
            
            if (left < right)
            {
                right = 0;
                left = 0;
            }
            else if (left == right)
            {
                maxL = max(maxL, 2 * left);
            }
        }
        
        left = 0;
        right = 0;
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            if (s[i] == '(')
            {
                left++;   
            }
            else
            {
                right++;
            }
            
            if (left > right)
            {
                right = 0;
                left = 0;
            }
            else if (left == right)
            {
                maxL = max(maxL, 2 * left);
            }
        }
        
        return maxL;
    }
};