/*
 * unordered_map: key, value cannot be switched
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketMap{
            {')', '('},			// cannot be switched
            {']', '['},
            {'}', '{'},
        };
        
        for (char i : s) {
            if (i == ')' || i == ']' || i == '}') {
                if (st.empty() || st.top() != bracketMap[i])
                    return false;
                st.pop();
            } else if (i == '(' || i == '[' || i == '{') {
                st.push(i);
            }
        }
        return st.empty();
    }
};
