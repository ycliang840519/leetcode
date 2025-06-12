class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int j = 0; j < strs[0].size(); j++){
            for (int i = 0; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[0][j] != strs[i][j])
                    return ans;
            }
            ans.push_back(strs[0][j]);
        }
        return ans;
    }
};

// using string's library 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].empty())
            return "";
        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            cout << prefix << endl;
            if (strs[i].find(prefix) != 0) {
                prefix.pop_back();
                i = 0;
            }
        }
        return prefix;
        
    }
};
