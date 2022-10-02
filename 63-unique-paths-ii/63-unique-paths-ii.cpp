class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m-1,n-1,obstacleGrid,dp);
    }
    int path(int i,int j,vector<vector<int>>&og,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && og[i][j]==1)return 0;
        if(i<0 || j<0)return 0;
        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int up= path(i-1,j,og,dp);
        int left=path(i,j-1,og,dp);
        return dp[i][j]= up+left;
    }
};