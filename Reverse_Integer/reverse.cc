class Solution {
public:
    int reverse(int x, int acc) {
        if (acc < INT_MIN / 10 || acc > INT_MAX / 10) {
            return 0;
        }
        if (acc == INT_MIN / 10 && x < -8) {
            return 0;
        }
        if (acc == INT_MAX / 10 && x > 7) {
            return 0;
        }
        if (x > -10 && x < 10) { return acc * 10 + x % 10; }
        return reverse(x / 10, acc * 10 + x % 10);
    }
    
    int reverse(int x) {
        if (x > -10 && x < 10) {
            return x; 
        }
        return reverse(x / 10, x % 10);
    }
};