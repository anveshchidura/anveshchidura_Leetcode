#include <vector>
#include <algorithm>
using namespace std;

int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        // Start of the grid
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        // Out of bounds of the grid
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        // Already computed
        return dp[i][j];
    }

    int up = f(i - 1, j, grid, dp);
    int left = f(i, j - 1, grid, dp);

    // Return minimum of up and left path, plus current cell's value
    return dp[i][j] = min(up, left) + grid[i][j];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, dp);
    }
};
