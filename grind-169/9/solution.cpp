class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string str = to_string(x);
        for(int i = 0; i < str.size()/2; i++) {
            if (str[i] != str[str.size() - 1 - i])
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long long int reverse = 0, tmp = x;
        while (tmp) {
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        
        return x == reverse;
    }
};
