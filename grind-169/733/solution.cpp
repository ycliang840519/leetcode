// DFS, resursive

class Solution {
public:
    void dfsFill(vector<vector<int>>& image, int sr, int sc, int color, int origColor) {
        int m = image.size(), n = image[0].size();
        if (sr >= m || sc >= n || sr < 0 || sc < 0) // not inside the image
            return;
        
        if (image[sr][sc] != origColor)             // not the same pixel
            return;

        if (origColor == color)                     // already the target color
            return;
        
        image[sr][sc] = color;

        dfsFill(image, sr + 1, sc,     color, origColor);
        dfsFill(image, sr,     sc + 1, color, origColor);
        dfsFill(image, sr - 1, sc,     color, origColor);
        dfsFill(image, sr,     sc - 1, color, origColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfsFill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

// BFS, iterative

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), origColor = image[sr][sc];
        
        queue<pair<int, int>> bfsQueue;
        bfsQueue.push(make_pair(sr,sc));

        while (!bfsQueue.empty()) {
            pair<int, int> curr = bfsQueue.front();
            bfsQueue.pop();

            // outside of image
            if (curr.first >= m || curr.second >= n || curr.first < 0 || curr.second < 0) 
                continue;
            if (image[curr.first][curr.second] != origColor)    // pixel not same
                continue;
            if (image[curr.first][curr.second] == color)    // already filled
                continue;

            image[curr.first][curr.second] = color;

            bfsQueue.push(make_pair(curr.first + 1, curr.second));
            bfsQueue.push(make_pair(curr.first    , curr.second + 1));
            bfsQueue.push(make_pair(curr.first - 1, curr.second));
            bfsQueue.push(make_pair(curr.first    , curr.second - 1));
        }

        return image;
    }
};

// syntax sugar: tuple packing
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), origColor = image[sr][sc];

        queue<pair<int, int>> bfsQueue;
        bfsQueue.push(make_pair(sr,sc));

        while (!bfsQueue.empty()) {
            auto [_sr, _sc] = bfsQueue.front();
            bfsQueue.pop();

            // outside of image
            if (_sr >= m || _sc >= n || _sr < 0 || _sc < 0)
                continue;
            if (image[_sr][_sc] != origColor)    // pixel not same
                continue;
            if (image[_sr][_sc] == color)    // already filled
                continue;

            image[_sr][_sc] = color;

            bfsQueue.push(make_pair(_sr + 1, _sc));
            bfsQueue.push(make_pair(_sr    , _sc + 1));
            bfsQueue.push(make_pair(_sr - 1, _sc));
            bfsQueue.push(make_pair(_sr    , _sc - 1));
        }

        return image;
    }
};
