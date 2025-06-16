class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int idx = ans.size() - 1;
            if (intervals[i][0] <= ans[idx][1] && intervals[i][1] > ans[idx][1])
                ans[idx][1] = intervals[i][1];
            else if (intervals[i][0] > ans[idx][1])
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
