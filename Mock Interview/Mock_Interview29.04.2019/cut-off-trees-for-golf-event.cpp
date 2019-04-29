//https://leetcode.com/problems/cut-off-trees-for-golf-event/
//I have to complete this after exam


class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int rows = forest.size();
        int cols = rows ? forest[0].size() : 0;
        
        if (!rows || !cols) {
            return 0;
        }
        
        // Start location is blocked
        if (forest[0][0] == 0) {
            return -1;
        }
        
        // Min queue of trees based on height
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> trees;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (forest[r][c] > 1) {
                   trees.push({forest[r][c], {r, c}}); 
                }
            }
        }
        
        // Legal moves
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Track visited
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        
        // Total distance
        int totalDist = 0;
        
        // Start location
        pair<int, int> start = {0, 0};
        
        // Tree ID
        int i = 0;
        
        // Iterate through trees in increasing height order
        while (!trees.empty()) {
            pair<int, int> to = trees.top().second;
            trees.pop();
            
            // Level order traversal
            bool found = false;
            int dist = -1;  
            queue<pair<int, int>> qu;
            
            qu.push({start.first, start.second});
            visited[start.first][start.second] = i;
            
            while (!qu.empty() && !found) {
                ++dist;
                
                for (int j = 0, r, c, size = qu.size(); j < size && !found; ++j) {
                    tie(r, c) = qu.front();
                    qu.pop();
                
                    // Break if target location found
                    if (r == to.first && c == to.second) {
                        found = true;
                        break;
                    }
                
                    for (int m = 0, nr, nc; m < 4; ++m) {
                        // New location
                        nr = r + moves[m].first;
                        nc = c + moves[m].second;

                        // Skip out of bound, blockages and already scheduled
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || visited[nr][nc] == i || forest[nr][nc] == 0) {
                            continue;
                        }
                            
                        // Mark visited asap otherwise it will be scheduled mutiple times
                        visited[nr][nc] = i;
                        qu.push({nr, nc});
                    }
                }
            }
            
            // Return if not found
            if (!found) {
                return -1;
            }
            
            // Update total distance
            totalDist += dist;
            
            // Update start
            start = to;
            
            // Update id
            ++i;
        }
        
        return totalDist;
    }
};
