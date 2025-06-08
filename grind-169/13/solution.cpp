class Solution {
    int charToInt(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            int curr = charToInt(s[i]);
            int next = charToInt(s[i+1]);
            if (curr < next)
                ans -= curr;
            else
                ans += curr;
        }
        ans += charToInt(s.back());
        
        return ans;
    }
};
