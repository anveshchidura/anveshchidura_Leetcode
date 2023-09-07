class Solution {
public:
    int rec_func(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){return dp[i][j];}
        else{
        int left = rec_func(m,n,i+1,j,dp);
        int right = rec_func(m,n,i,j+1,dp);
        dp[i][j] = left + right;
        return dp[i][j];
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, -1));
        int answer = rec_func(m,n,0,0,dp);
        return answer;
    }
};