class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [] (const auto& a, const auto& b) {
            enum { X, Y };
            return std::pow(a[X], 2) + std::pow(a[Y], 2) <
                   std::pow(b[X], 2) + std::pow(b[Y], 2);
        };
        std::ranges::nth_element(points, points.begin()+k, comparator);
        points.resize(k);
        return std::move(points);
    }
};

// lamda expression
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [] (const auto &a, const auto &b) {
            enum {x, y};
            return std::pow(a[x], 2) + std::pow(a[y], 2)  <
                   std::pow(b[x], 2) + std::pow(b[y], 2); 
        };
        std::ranges::nth_element(points.begin(), points.begin() + k, points.end(), comparator);
        points.resize(k);
        return std::move(points);
    }
};

// priority queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        for(int i = 0; i < points.size(); i++) {
            int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({dist, i});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};
