class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            if (n == INT_MIN)
            {
                return 1 / x * myPow(1 / x, INT_MAX);
            }
            return myPow(1 / x, - n);
        }
        else if (n == 1)
        {
            return x;
        }
        else if (n == 0)
        {
            return 1;
        }
        double pow = x;
        int nPow = 1;
        while (nPow <= n / 2)
        {
            pow *= pow;
            nPow += nPow;
        }
        
        return pow * myPow(x, n - nPow);
    }
};