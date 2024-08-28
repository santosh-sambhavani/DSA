class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int color1 = image[sr][sc], m = image.size(), n = image[0].size();
        // vector<vector<int>> res = image;

        q.push({sr, sc});
        image[sr][sc] = color;
        cout << "\n sr || sc: " << sr << " || " << sc;
        // while(!q.empty()) {
        //     pair<int, int> front = q.front();
        //     cout << "\n ====> fornt: " 
        //          << front.first << " || " 
        //          << front.second 
        //          << " || color: " << image[front.first][front.second];
        //     vector<pair<int, int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        //     for (auto &it: dir) {
        //         if (
        //             front.first+it.first >= 0 
        //             && front.first+it.first < m
        //             && front.second+it.second >= 0
        //             && front.second+it.second < n
        //             && res[front.first+it.first][front.second+it.second] == color1
        //         ) {
        //             q.push({front.first+it.first, front.second+it.second});
        //             // res[front.first+it.first][front.second+it.second] = color;
        //             cout << "\n ===> iteration pixel: " 
        //                  << front.first+it.first 
        //                  << " ||| " 
        //                  << front.second+it.second
        //                  << " || color: " << res[front.first+it.first][front.second+it.second];
        //         }
        //     }
        //     q.pop();
        // }
        while (!q.empty()) {
            pair front = q.front();
            if (front.first + 1 < m &&
                image[front.first + 1][front.second] == color1
            ) {
                q.push({front.first + 1, front.second});
                image[front.first + 1][front.second] = color;
            }
            if (front.second + 1 < n &&
                image[front.first][front.second + 1] == color1
            ) {
                q.push({front.first, front.second + 1});
                image[front.first][front.second + 1] = color;
            }
            if (front.first - 1 >= 0 &&
                image[front.first - 1][front.second] == color1
            ) {
                q.push({front.first - 1, front.second});
                image[front.first - 1][front.second] = color;
            }
            if (front.second - 1 >= 0 &&
                image[front.first][front.second - 1] == color1
            ) {
                q.push({front.first, front.second - 1});
                image[front.first][front.second - 1] = color;
            }
            q.pop();
        }

        return res;
    }
};
