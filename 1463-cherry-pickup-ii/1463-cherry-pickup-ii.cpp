class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,n,m,dp);
    }
    int f(int i,int j1,int j2,vector<vector<int>> &grid,int n,int m,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m)return -1e8;
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        if(i==n-1){
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi=-1e8;
        for(int dp1=-1;dp1<=1;dp1++){
            for(int dp2=-1;dp2<=1;dp2++){
                
                int value=0;
                if(j1==j2)value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=f(i+1,j1+dp1,j2+dp2,grid,n,m,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
};