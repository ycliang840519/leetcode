class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++) {
	    // if i is odd => the number of 1's for i is equal to (that of i/2) + 1
	    // binary representation of odd number -> xxxx1
	    // if i is even => the number of 1's for i is equal to (that of i/2)
	    // binary representation of even number-> xxxx0
            if (i & 1)
                ans.push_back(ans[i/2] + 1);
            else
                ans.push_back(ans[i/2]);
        }
        return ans;
    }
};
