class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end() && (*it)[0] < newInterval[0]) it++;
        intervals.insert(it, newInterval);
        
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans[ans.size() - 1][1])
                ans.push_back(intervals[i]);
            else
                ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end() && (*it)[0] < newInterval[0]) it++;
        intervals.insert(it, newInterval);
        
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
        return ans;
    }
};
