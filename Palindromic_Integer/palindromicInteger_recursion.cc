class Solution {
public:
    bool match(int left, int right) {
        if (right >= left) {
            return left == right || left == right / 10;
        }
        return match(left / 10, right * 10 + left % 10);
    }
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        } 
        
        return match(x / 10, x % 10);
    }
};