class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,minsum(n-1,i,n,matrix,dp));
        }
        return mn;
    }
    int minsum(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
         if(j<0 || j>=n)return 1e9;
        if(i==0)return matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int s=matrix[i][j]+minsum(i-1,j,n,matrix,dp);
        int ld=matrix[i][j]+minsum(i-1,j-1,n,matrix,dp);
        int rd=matrix[i][j]+minsum(i-1,j+1,n,matrix,dp);
        return dp[i][j]= min(s,min(ld,rd));
    }
};