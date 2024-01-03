int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
    if(i==0 && j==0){
        return obstacleGrid[i][j] == 1 ? 0 : 1;
    }
    if(i<0 || j<0){
        return 0;
    } 
    if(obstacleGrid[i][j] == 1){
        return 0;
    }    
    if(dp[i][j] != -1) { return dp[i][j];};
    
    int up = i > 0 ? f(i - 1, j, obstacleGrid, dp) : 0;
    int left = j > 0 ? f(i, j - 1, obstacleGrid, dp) : 0;
    
    return dp[i][j] = up + left;
    
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m =  obstacleGrid.size();
        int n =  obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return f(m-1,n-1,obstacleGrid,dp);;
        
    }
};