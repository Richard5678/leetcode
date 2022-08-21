
class Solution {
public:
    int divide(int dividend, int divisor) {
        int dividendCopy = abs(dividend);
        int divisorCopy = abs(divisor);
        int answer = 0;
        if (divisor == INT_MIN)
        {
            return dividend == divisor;
        } 
        else if (dividend == INT_MIN)
        {
            dividendCopy = abs(dividend + abs(divisor));
            if (abs(divisor) == 1)
            {
                return (divisor == 1) ? INT_MIN : INT_MAX;
            }
            answer++;
        }
        int HALF_INT_MAX = 1073741824;
        while (dividendCopy >= divisorCopy)
        {
            int power = 1;
            int value = divisorCopy;
            while(value < HALF_INT_MAX && value + value <= dividendCopy){
                value += value;
                power += power;
            }
            dividendCopy -= value;
            answer += power;
        }
        
        if ((dividend > 0 && divisor > 0) || 
              (dividend < 0 && divisor < 0))
        {
            return answer;
        }
        
        return -answer;
    }
};