class Solution {
public:
    string longestPalindrome(string s) {
        string strCopy;
        for (int i = 0; i < s.length(); i++)
        {
            strCopy += "|";
            strCopy += s[i];
        }
        strCopy += "|";
        vector<int> radius(strCopy.length(), 0);
        int r = 0;
        int center = 0;
        while (center < strCopy.length())
        {
            while (center + r + 1 < strCopy.length() && center - r - 1 >= 0 && 
                   strCopy[center + r + 1] == strCopy[center - r - 1])
            {
                r++;
            }
            radius[center] = r;
            int rightLimit = center + r;
            int centerIdx = center;
            center++;
            r = 0;
            while (center <= rightLimit)
            {
                int mirrorIdx = 2 * centerIdx - center;
                if (center + radius[mirrorIdx] != rightLimit)
                {
                    radius[center] = min(radius[mirrorIdx], rightLimit - center);
                    center++;
                }
                else 
                {
                    r = rightLimit - center;
                    break;
                }
            }
        }
        int maxIdx = max_element(radius.begin(), radius.end()) - radius.begin();
        int maxRadius = (radius[maxIdx] - 1) / 2;
        int maxCenter = (maxIdx - 1) / 2;
        
        if (maxIdx % 2 != 0)
        {
            return s.substr(maxCenter - maxRadius, 2 * maxRadius + 1);
        }
        return s.substr(maxCenter - maxRadius, 2 * maxRadius + 2);
    }
};