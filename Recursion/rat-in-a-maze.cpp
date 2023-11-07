private: 
        bool checkPoint (vector<vector<int>> m, int x, int y, int n, vector<vector<int>> visited) {
            return (x == -1 || x == n || y == -1 || y == n || m[x][y] == 0 || visited[x][y] == 1) ? false : true;
        }
        
        void generatePaths(
            vector<vector<int>> m, 
            int rawIndex,
            int colIndex,
            int n, 
            string output, 
            vector<string> result,
            vector<vector<int>> &visited
        ) {
            if (rawIndex == n-1 && colIndex == n-1) {
                result.push_back(output);
                return;
            } 
            
            // check down
            if (checkPoint(m, rawIndex + 1, colIndex, n, visited)) {
                // go down
                rawIndex++;
                visited[rawIndex][colIndex] = 1;
                output += 'D';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                rawIndex--;
                output = output.substr(0, output.size() - 1);
            }
            
            // check up
            if (checkPoint(m, rawIndex - 1, colIndex, n, visited)) {
                // go up
                rawIndex--;
                visited[rawIndex][colIndex] = 1;
                output += 'U';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                rawIndex++;
                output = output.substr(0, output.size() - 1);
            }
            
            // check right 
            if (checkPoint(m, rawIndex, colIndex + 1, n, visited)) {
                // go right
                colIndex++;
                visited[rawIndex][colIndex] = 1;
                output += 'R';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                colIndex--;
                output = output.substr(0, output.size() - 1);
            }
            
            // check left
            if (checkPoint(m, rawIndex, colIndex - 1, n, visited)) {
                // go left
                colIndex--;
                visited[rawIndex][colIndex] = 1;
                output += 'L';
                generatePaths(m, rawIndex, colIndex, n, output, result, visited);
                
                // backtrack
                visited[rawIndex][colIndex] = 0;
                colIndex++;
                output = output.substr(0, output.size() - 1);
            }
        }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if (m[0][0] == 0 || m[n-1][n-1] == 0)
            return {};
        vector<string> result;
        vector<vector<int>> visited {
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        generatePaths(m, 0, 0, n, "", result, visited);
    }
