class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,grid,dp);
    }
    int fn(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=grid[i][j]+fn(i-1,j,grid,dp);
        int left=grid[i][j]+fn(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
};